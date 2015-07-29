#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int inf = ~0u >> 2;
int cnt , P , p[10000] , q[10000] , n , f[11000] , his[11000] , ans[11000] , k;
bool prime[10010];
void output(int x)
{
    if ( x <= 0 ) return ;
    ans[++k] = x - his[x];
    output(his[x]);
}

int main()
{
    P = 0;
    memset(prime , 0 , sizeof(prime));
    for (int i = 2 ; i <= 10000 ; i ++)
    {
        if (!prime[i])
        {
            p[++P] = i;
            for (int j = i ; j <= 10000 ; j += i )
            {
                prime[j] = 1;
            }
        }
    }
    cnt = 0;
    for (int i = 1; i <= P ; i ++)
    {
        if (p[i] <= P) q[++cnt] = p[p[i]];
    }
    while ( scanf("%d",&n) == 1 )
    {
        for (int i = 1; i <= 10086 ; i ++)
        {
            f[i] = - inf;
        }
        f[0] = 0;
        for (int i = 1; i <= cnt ; i ++)
        {
            for (int j = q[i] ; j <= n ; j ++)
            {
                if (f[j] < f[j-q[i]] - 1)
                {
                    f[j] = f[j-q[i]] - 1;
                    his[j] = j - q[i];
                }
            }
        }
        if (f[n] == -inf) printf("0\n");
        else 
        {
            printf("%d\n",-f[n]);
            k = 0;
            output(n);
            sort(ans + 1, ans + k + 1);
            for (int i = k ; i > 1; i --) printf("%d ",ans[i]);
            printf("%d\n",ans[1]);
        }
    }
}
