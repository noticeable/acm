��Ŀ3 : ���ȡ��
ʱ������:2000ms
����ʱ��:1000ms
�ڴ�����:256MB
����
����һ��m x n (1 <= m, n <= 100)�ľ���A (0<=aij<=10000)��Ҫ���ھ�����ѡ��һЩ����Ҫ��ÿһ�У�ÿһ�ж�����ѡ����һ������ʹ��ѡ�������ĺ;�����С��
����
����������ݡ���������������T
����ÿ��������ݣ���1��������������m, n���ֱ��ʾ�����������������
��������m�У�ÿ��n��������֮����һ���ո�ָ�����ʾ����A��Ԫ�ء�
���
ÿ���������һ�У���ʾѡ�������ĺ͵���Сֵ��
���ݷ�Χ
С���ݣ�1 <= m, n <= 5
�����ݣ�1 <= m, n <= 100

��������ͼ�����2*m���㣬�ұ�2*n���㣬���ǰm��Ϊ�˱�֤��ѡ��m�У�S->i��(1,-inf)�ı�
��m�������ṩ������S->i+m��(inf,0)�ıߣ�������������
//////////////////////////////////////////////////////////
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
const int maxn=500+10;
const int maxm=100000+10;
const int maxv=100000;
struct Edge
{
    int to,cap,cost,next;
    Edge(){}
    Edge(int to,int cap,int cost,int next):to(to),cap(cap),cost(cost),next(next){}
}edges[maxm<<1];
int head[maxn],d[maxn],p[maxn],a[maxn],nEdge;
bool inq[maxn];
void AddEdges(int from,int to,int cap,int cost)
{
    edges[++nEdge]=Edge(to,cap,cost,head[from]);
    head[from]=nEdge;
    edges[++nEdge]=Edge(from,0,-cost,head[to]);
    head[to]=nEdge;
}
bool spfa(int s,int t,int &flow,int &cost)
{
    queue<int>q;
    for(int i=0;i<=t;++i)
    {
        d[i]=inf;
        inq[i]=false;
    }
    d[s]=0;a[s]=inf;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        inq[u]=false;
        for(int k=head[u];k!=-1;k=edges[k].next)
        {
            Edge e=edges[k];
            if(d[e.to]>d[u]+e.cost&&e.cap)
            {
                d[e.to]=d[u]+e.cost;
                p[e.to]=k;
                a[e.to]=min(a[u],e.cap);
                if(!inq[e.to]) {inq[e.to]=false;q.push(e.to);}
            }
        }
    }
    if(d[t]==inf||d[t]>=0) return false;
    flow+=a[t];
    cost+=a[t]*d[t];
    int u=t;
    while(u!=s)
    {
        edges[p[u]].cap-=a[t];
        edges[p[u]^1].cap+=a[t];
        u=edges[p[u]^1].to;
    }
    return true;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,tcase=0,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        int S=0,T=2*m+2*n+1,val;
        memset(head,0xff,sizeof(head));
        nEdge=-1;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
            {
                scanf("%d",&val);
                AddEdges(i,2*m+j,1,val);
                AddEdges(i,2*m+n+j,1,val);
                AddEdges(i+m,2*m+j,1,val);
            }
        for(int i=1;i<=m;++i)
        {
            AddEdges(S,i,1,-maxv);
            AddEdges(S,i+m,inf,0);
        }
        for(int i=1;i<=n;++i)
        {
            AddEdges(2*m+i,T,1,-maxv);
            AddEdges(2*m+i+n,T,inf,0);
        }
        int flow=0,cost=0;
        while(spfa(S,T,flow,cost));
        int ans=cost+maxv*(m+n);
        printf("Case %d: %d\n",++tcase,ans);
    }
    return 0;
}

