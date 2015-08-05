#include<iostream>
#include<cstdio>
using namespace std;
int tot;
int mu[50005] , sum[50005] , pr[50005];
bool mark[50005];
void prepare()
{
    mu[1] = 1;
    for (int i = 2 ; i <= 50000; i++)
    {
        if (!mark[i])
        {
            pr[++tot] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= tot && i * pr[j] <= 50000; j ++)
        {
            mark[i * pr[j]] = 1;
            if ( i %pr[j] == 0)
            {
                mu[i * pr[j]] = 0;
                break;
            }
            else mu[i*pr[j]] = -mu[i];
        }
    }
    for (int i = 1 ; i <= 50000; i ++)
        sum[i] = sum[i - 1] + mu[i];
}

int main()
{
    prepare();
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
        int a , b , d;
        scanf("%d%d%d",&a,&b,&d);
        a /= d;
        b /= d;
        if (a > b) swap(a , b);
        int ans = 0 , pos;
        for (int i = 1; i <= a ; i = pos + 1)
        {
            pos = min(a / (a / i) , b / (b / i));
            ans += (sum[pos] - sum[i - 1]) *(a / i) * (b / i);
        }
        printf("%d\n",ans);
    }
}
