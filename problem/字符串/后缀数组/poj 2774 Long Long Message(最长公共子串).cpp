#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=200000+100;
char s[maxn],s2[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn];
int height[maxn],rank[maxn];
void build_sa(int n,int m)
{
    int i,*x=t,*y=t2;
    for(i=0;i<m;++i) c[i]=0;
    for(i=0;i<n;++i) c[x[i]=s[i]]++;
    for(i=1;i<m;++i) c[i]+=c[i-1];
    for(i=n-1;i>=0;--i) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1)
    {
        int p=0;
        for(i=n-k;i<n;++i) y[p++]=i;
        for(i=0;i<n;++i) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(i=0;i<m;++i) c[i]=0;
        for(i=0;i<n;++i) c[x[y[i]]]++;
        for(i=1;i<m;++i) c[i]+=c[i-1];
        for(i=n-1;i>=0;--i) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;++i)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}
void getHeight(int n)
{
    int i,j,k=0;
    for(i=0;i<=n;++i) rank[sa[i]]=i;
    for(i=0;i<n;++i)
    {
        if(k) k--;
        j=sa[rank[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rank[i]]=k;
    }
}
bool check(int n,int x,int y)
{
    return (x<n&&y>n)||(x>n&&y<n);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n1,n2,n;
    scanf("%s",s);
    scanf("%s",s2);
    n1=strlen(s);
    n2=strlen(s2);
    n=n1+n2+1;
    s[n1]='$';
    for(int i=0;i<=n2;++i)
        s[n1+i+1]=s2[i];
    build_sa(n+1,200);
    getHeight(n);
    int maxlen=-1;
    for(int i=2;i<=n+1;++i)
        if(height[i]>maxlen&&check(n1,sa[i],sa[i-1]))
            maxlen=height[i];
    printf("%d\n",maxlen);
    return 0;
}

