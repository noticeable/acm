#include <iostream>
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
const int maxn=1000+10;
vector<int>G[maxn];
int link[maxn];
bool used[maxn];
bool dfs(int u)
{
    for(int i=0;i<G[u].size();++i)
    {
        int v=G[u][i];
        if(!used[v])
        {
            used[v]=true;
            if(link[v]==-1||dfs(link[v]))
            {
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary(int n)
{
    int res=0;
    memset(link,0xff,sizeof(link));
    for(int i=1;i<=n;++i)
    {
        memset(used,0,sizeof(used));
        if(dfs(i)) res++;
    }
    return res;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,k;
    while(~scanf("%d",&m))
    {
        if(m==0) break;
        scanf("%d",&n);
        for(int i=0;i<=n;++i) G[i].clear();
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&k);
            int c;
            for(int j=0;j<k;++j)
            {
                scanf("%d",&c);
                G[i].push_back(c);
            }
        }
        int ans=hungary(n);
        printf("%d\n",ans);
    }
    return 0;
}
