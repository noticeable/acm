#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=1000+10;
const int move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int vis[maxn][maxn],lf[maxn][maxn],ups[maxn][maxn];
int maze[maxn][maxn],total,n,m,sx,sy,degree,k;
bool check(int x,int y,int dx,int dy)
{
    if(dx<1||dx>n||dy<1||dy>m) return false;
    if(x==dx)
    {
        if(y>dy) swap(y,dy);
        return lf[x][dy]-lf[x][y-1]==k+1;
    }
    if(x>dx) swap(x,dx);
    return ups[dx][y]-ups[x-1][y]==k+1;
}
int dfs(int x,int y)
{
    int dx,dy;
    int dg=0,ret=2;
    for(int i=0;i<4;++i)
    {
        dx=x+move[i][0]*k;
        dy=y+move[i][1]*k;
        if(check(x,y,dx,dy))
        {
            dg++;
            ret+=k-1;
            if(vis[dx][dy]!=k){vis[dx][dy]=k;ret+=dfs(dx,dy);}
        }
    }
    degree+=dg&1;
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        memset(lf,0,sizeof(lf));
        memset(ups,0,sizeof(ups));
        total=0;
        sx=0;
        for(int i=1;i<=n;++i)
          for(int j=1;j<=m;++j)
          {
              scanf("%d",&maze[i][j]);
              total+=maze[i][j];
              if(!sx&&maze[i][j]) sx=i,sy=j;
              lf[i][j]=lf[i][j-1]+maze[i][j];
              ups[i][j]=ups[i-1][j]+maze[i][j];
          }
        if(total==1){printf("-1\n");continue;}
        int mx=min(n,m);
        bool f=true;
        for(k=2;k<=mx;++k)
        {
          vis[sx][sy]=k;
          degree=0;
          if(dfs(sx,sy)==total*2&&(degree==0||degree==2))
          {
              if(!f) printf(" ");
              f=false;
              printf("%d",k);
          }
        }
        if(f) printf("-1\n");
        else printf("\n");
    }
    return 0;
}
