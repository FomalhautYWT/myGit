#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const long long MOD = 1e9 + 7;
long long fact[500];
bool v[200];
long long a[200][200];
long long now[1000];
int main()
{
    fact[0] = 1;
    for (int i = 1; i <= 100 ; i ++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    int n ,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        long long ans = 0;
        for (int i = 1; i <= m ; i ++)
        {
            scanf("%I64d",&a[i][1]);
            if (a[i][1]!=-1)
            {
                for (int j = 2; j <= n ; j ++)
                {
                    scanf("%I64d",&a[i][j]);
                }
            }
            else {
                ans ++;
            }
        }
        for (int i = 1; i <= n ; i ++)
            now[i] = i;
        for (int i = m ; i >= 1 ; i --)
        {
            if (a[i][1] == -1) continue;
            for (int j = 1; j <= n ; j ++)
            {
                now[j] = a[i][now[j]];
            }
        }
        bool flag = true;
        memset(v,0,sizeof(v));
        for (int i = 1 ; i <= n ; i ++)
        {
            if (v[now[i]]) flag = false;
            v[now[i]] = true;
        }
        long long theAns = 1;
        if (flag)
        {
            bool yes = true;
            if (ans == 0)
            {
                for (int i = 1; i <= n ; i ++)
                    if (now[i]!=i) yes = false;
            }
            if (yes)
            {
                for (int i = 1; i < ans ; i ++)
                {
                    theAns *= fact[n];
                    theAns %= MOD;
                }
                printf("%I64d\n",theAns);
            }
            else{
                printf("0\n");
            }
        }
        else{
            puts("0");
        }

    }
}
