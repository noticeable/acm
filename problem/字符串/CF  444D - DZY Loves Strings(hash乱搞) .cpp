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
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long Ull;
const int mx = 233;
const int maxn = 50000+10;
const int maxm = 600000+10;
char str[maxn],sa[11],sb[11];
vector<int>vt[maxm];
map<int,int>mp[maxm];
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%s",str);
    int n = strlen(str);
    for(int i = 0;i < n;++i)
    {
        int val = 0;
        for(int j = 0;j < 4 && i + j < n;++j)
        {
            val = val * 27 + str[i+j] - 'a' + 1;
            vt[val].push_back(i);
        }
    }
    int q,va,vb,tmp,ans;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s%s",sa,sb);
        int lena = strlen(sa);
        int lenb = strlen(sb);
        va = vb = 0;
        for(int i = 0 ;i < lena;++i)
            va = va*27 + sa[i] - 'a' +1;
        for(int i = 0;i < lenb;++i)
            vb = vb*27 + sb[i] - 'a' +1;
        if(mp[va].find(vb) != mp[va].end())
        {
            ans = mp[va][vb];
        }
        else
        {
            int i = 0 ,j = 0,x,y;
            ans = inf;
            while(i < (int)vt[va].size() && j < (int)vt[vb].size())
            {
                x = vt[va][i];
                y = vt[vb][j];
                tmp = max(x+lena,y+lenb) - min(x,y);
                ans = min(ans,tmp);
                if(x < y) i++;
                else j++;
            }
            if(ans == inf) ans = -1;
            mp[va][vb] = ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}
