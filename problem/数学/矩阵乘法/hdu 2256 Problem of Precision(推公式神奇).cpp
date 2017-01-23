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
const int mod=1024;
struct Matrix
{
    int mat[2][2];
    void Init()
    {
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                mat[i][j]=(i==j);
    }
    void clear(){memset(mat,0,sizeof(mat));}
};
Matrix operator *(const Matrix &a,const Matrix &b)
{
    Matrix c;c.clear();
    for(int k=0;k<2;++k)
        for(int i=0;i<2;++i)
            for(int j=0;j<2;++j)
                c.mat[i][j]=(c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
    return c;
}
int solve(int n)
{
    if(n==1) return 9;
    Matrix x,y;
    x.Init();
    y.mat[0][0]=y.mat[1][1]=5;
    y.mat[0][1]=2;y.mat[1][0]=12;
    n-=1;
    while(n)
    {
        if(n&1) x=x*y;
        y=y*y;
        n>>=1;
    }
    int ans=(5*x.mat[0][0]+2*x.mat[1][0])%mod;
    return ((ans*2-1)%mod+mod)%mod;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",solve(n));
    }
    return 0;
}
