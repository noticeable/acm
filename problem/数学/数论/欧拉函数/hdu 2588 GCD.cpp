#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=50000+10;
int primes[maxn],pcnt;
bool flag[maxn];
void getprimes()
{
    memset(flag,0,sizeof(flag));
    pcnt=0;
    for(int i=2;i<maxn;++i)
    {
        if(!flag[i])
        {
            primes[pcnt++]=i;
            for(ll j=(ll)i*i;j<maxn;j+=i)
                flag[j]=true;
        }
    }
}
int euler_phi(int n)
{
    int ans=n;
    for(int i=0;i<pcnt&&n>=primes[i];++i)
    {
        if(n%primes[i]==0)
        {
            ans=ans-ans/primes[i];
            while(n%primes[i]==0) n/=primes[i];
        }
    }
    if(n>1) ans=ans-ans/n;
    return ans;
}
int factor[110],num[110],tot,n,ans,N,M;
void dfs(int pos,int now)
{
    if(pos==tot)
    {
        if(now!=1&&now>=M&&now<=N) ans+=euler_phi(N/now);
        return ;
    }
    int tmp=1;
    for(int i=0;i<=num[pos];++i)
    {
        dfs(pos+1,now*tmp);
        tmp*=factor[pos];
    }
}
int solve()
{
    n=N;tot=0;ans=0;
    for(int i=0;i<pcnt&&n>=primes[i];++i)
    {
        if(n%primes[i]==0)
        {
            factor[tot]=primes[i];num[tot]=0;
            while(n%primes[i]==0) {n/=primes[i];num[tot]++;}
            tot++;
        }
    }
    if(n>1) {factor[tot]=n;num[tot++]=1;}
    n=N;
    dfs(0,1);
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    getprimes();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&M);
        int res;
        if(M==1) res=N;
        else res=solve();
        printf("%d\n",res);
    }
    return 0;
}
