//��dΪa,b��Լ������ôa,b��a/d,b/d����ͬ�Ľ��
//��a+bΪ��������ô�޽�
//ÿ�μ���(a-b)/2,b�Ϳ����
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
int cal(ll x,ll y)
{
    if(x==0||y==0) return 0;
    if((x+y)&1) return -1;
    if(x<y) swap(x,y);
    int ret=cal((x-y)/2,y);
    if(ret==-1) return -1;
    return ret+1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b;
    while(cin>>a>>b)
    {
        int ans=cal(a,b);
        printf("%d\n",ans);
    }
    return 0;
}
