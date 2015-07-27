#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std;
const int max_n = 200000;
const int max_m = 200000;
typedef set<int>::iterator it;
set<int> s;
int n , m ;
int pre[max_m];
int other[max_m];
int len[max_m];
int last[max_n];
int dfn[max_n];
int dis[max_n];
int times = 0;
int antidfn[max_n];
int dp[max_n][60];
int deep[max_n];
int f[max_n];
int l = 0;
void add_edge(int x ,int y , int c)
{
    pre[++l] = last[x] ; last[x] = l ; other[l] = y ; len[l] = c;
    pre[++l] = last[y] ; last[y] = l ; other[l] = x ; len[l] = c;
}
void dfs(int x ,int fa)
{
    dfn[x] = ++times;
    antidfn[times] = x;
    for (int p = last[x] ; p != 0 ; p = pre[p])
    {
        if (other[p] != fa)
        {
            f[other[p]] = x;
            deep[other[p]] = deep[x] + 1;
            dis[other[p]] = dis[x] + len[p];
            dfs(other[p] , x);
        }
    }
}
void prepare()
{
    for (int i = 1 ; i <= n ; i ++)
    {
        dp[i][0] = f[i];
    }
    for (int i = 1 ; i <= 50 ; i ++)
    {
        for (int j = 1 ; j <= n ; j ++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
    }
}
int lca(int x,int y)
{
    if ( x == y ) return x;
    if (deep[x] < deep[y]) swap(x , y);
    int t = deep[x] - deep[y] ;
    for (int i = 0 ; t != 0 ; i ++ , t >>= 1)
        if (t & 1) x = dp[x][i];
    if (x == y) return x;
    for (int i = 0 ; x != y ;)
    {
        if ((dp[x][i]!=dp[y][i]) || ((dp[x][i]==dp[y][i]) && (i == 0)))
        {
            x = dp[x][i];
            y = dp[y][i];
            i ++;
        }
        else i --;
    }
    return x;

}
int add(int u)
{
    if (s.empty()) return 0;
    int x, y;
    it it0 = s.lower_bound(dfn[u]) , itx = it0;
    itx --;
    if (it0 == s.end() || it0 == s.begin())
    {
        it0 = s.begin();
        itx = s.end();
        itx --;
    }
    y = (*it0);
    x = (*itx);
    y = antidfn[y];
    x = antidfn[x];
    return dis[u] - dis[lca(x,u)] - dis[lca(y,u)] + dis[lca(x,y)];
}
bool isin[max_n];
int main()
{
    //freopen("1009.in","r",stdin);
    //freopen("1009.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    for (int _ = 1 ; _ <= cas ; _ ++)
    {
        printf("Case #%d:\n",_);
        s.clear();
        l = 0;
        times = 0;
        memset(deep,0,sizeof(deep));
        memset(f,0,sizeof(f));
        memset(dp,0,sizeof(dp));
        memset(dfn,0,sizeof(dfn));
        memset(antidfn,0,sizeof(antidfn));
        memset(isin,0,sizeof(isin));
        memset(dis,0,sizeof(dis));
        memset(pre,0,sizeof(pre));
        memset(other,0,sizeof(other));
        memset(last,0,sizeof(last));

        int ans = 0;
        scanf("%d%d",&n,&m);
        for (int i = 1; i < n ; i ++)
        {
            int x , y , k;
            scanf("%d%d%d",&x,&y,&k);
            add_edge(x,y,k);
        }
        dfs(1, 1);
        prepare();
        for (int i = 1; i <= m ; i ++)
        {
            int ok , x;
            scanf("%d%d",&ok,&x);
            if (ok == 1)
            {
                if (!isin[x]){
                    isin[x] = true;
                    if (s.size() == 0)
                        s.insert(dfn[x]);
                    else{
                        int tmp = add(x);
                        s.insert(dfn[x]);
                        ans += tmp;
                    }
                }
            }
            else {
                if (isin[x])
                {
                    isin[x] = false;
                    s.erase(dfn[x]);
                    if(s.size()!=0)
                        ans -= add(x);
                }
            }
            printf("%d\n",ans);
        }
    }
    //fclose(stdin);
    //fclose(stdout);
}
