#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas --)
    {
        long long n, m , z , l;
        scanf("%I64d%I64d%I64d%I64d",&n,&m,&z,&l);
        long long ans = 0;
        long long now = 0;
        for (int i = 2; i <= n ; i ++)
        {
            now = (now * m + z) % l;
            ans ^= now * 2;
        }
        printf("%I64d\n",ans);
    }
}
