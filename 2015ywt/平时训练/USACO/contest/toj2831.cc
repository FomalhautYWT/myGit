#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
using namespace std;
int pre[8000] , other[8000] , last[1000] ;
int que[500004];
bool v[2000];
int len[8000];
int d[2000];
int dist[2000];
int n , m , w;
int l = 0;
const int inf = ~0u >> 1;
void add_edge(int p ,int q ,int r)
{
    pre[++l] = last[p] ; last[p] = l ; other[l] = q ; len[l] = r;
}
bool spfa()
{
    memset(v , 0 , sizeof(v));
    memset(que, 0 ,sizeof(que));
    int l = 0 , r = 0 ;
    que[++r] = 1 ;
    for (int i= 1; i <= n ; i ++) dist[i] = inf;
    dist[1] = 0;
    while ( l != r )
    {
        l ++;
        if ( l >500000 ) l = 1;
        int x = que[l] ;
        for (int p = last[x] ; p != 0 ; p = pre[p])
        {
            if (dist[x] + len[p] < dist[other[p]])
            {
                dist[other[p]] = dist[x] + len[p];
                d[other[p]] ++;
                if (d[other[p]] > n) return true;
                if ( !v[other[p]] )
                {
                    ++ r;
                    if ( r > 500000 ) r = 1;
                    que[r] = other[p] ;
                    v[other[p]] = 1 ;
                }
            }
        }
        v[x] = false;
    }
//    for (int i = 1 ; i <= r ; i ++) cout << que[i] << endl;
    return false ;

}
int main()
{
    int caseTest;
    scanf("%d",&caseTest);
    while ( caseTest-- )
    {
        int p , q , r;
        l = 0;
        memset(d,0,sizeof(d));
        memset(pre,0,sizeof(pre));
        memset(last,0,sizeof(last));

        scanf("%d%d%d",&n,&m,&w);
        for (int i = 1; i <= m ; i ++)
        {
            scanf("%d%d%d",&p,&q,&r);
            add_edge(p,q,r);
            add_edge(q,p,r);
        }
        for (int i = 1; i <=  w ; i ++)
        {
            scanf("%d%d%d",&p,&q,&r);
            add_edge(p,q,-r);
        }
        if (spfa())
        puts("YES");
        else puts("NO");
    }
}
