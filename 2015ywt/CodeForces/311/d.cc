#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n , m ;
int pre[300000] , other[300000] , last[300000];
long long d1 = 0 , d0 = 0;
int l = -1;
int vis[300000];
void add_edge(int x,int y)
{
    pre[++l] = last[x] ;last[x] = l ; other[l] = y;
    pre[++l] = last[y] ;last[y] = l ; other[l] = x;
}
int flag = 0;
void dfs(int x)
{
    //cout <<"!!" << x << " " << d0 <<" " << d1 <<endl;

    if (vis[x] == 1)
        d1 ++;
    else d0++;

    for (int p = last[x]; p != -1 ;p = pre[p])
    {
        if (vis[other[p]])
        {
            if (vis[other[p]] == vis[x]){
                flag = 1;
                return;
            }
            continue;
        }
        vis[other[p]] = 3 - vis[x];
        dfs(other[p]);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0 ; i <= n + 1; i ++)
        last[i] = -1;
    memset(vis , 0 , sizeof(vis));
    for (int i = 1; i <= m ; i ++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        add_edge(a , b);
    }
    long long ans = 0;
    if ( m == 0 )
    {
        printf("3 %I64d\n",n * ( n - 1 ) * (n - 2)/6);
        return 0;
    }

    for (int i = 1; i <= n ; i ++)
    {
        d0 = 0;
        d1 = 0;
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i);
            ans += d0 * (d0 - 1) / 2;
            ans += d1 * (d1 - 1) / 2;
            //cout <<"!" << i << " " << d0 << " " << d1 << endl;
        }
    }
    if (flag) printf("0 1\n");else
    if ( ans == 0 ) printf("2 %I64d\n",m * (n - 2));
    else printf("1 %I64d\n",ans);
}
