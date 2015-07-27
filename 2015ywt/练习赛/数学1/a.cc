#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
long long MOD = 0;
long long n;
long long cal(long long x ,long long y)
{
    long long ans = 1;
    long long temp = x;
    while (y)
    {
        if ( y & 1)
            ans = ((ans % MOD)* (temp % MOD))%MOD;
        temp = ((temp%MOD) * (temp%MOD))%MOD;
        y >>= 1;
    }
    return ans;
}
long long ans;
int main()
{
    while (scanf("%I64d",&n),n)
    {
        MOD = n;
        ans = cal(2 , n - 1);
        ans ++;
        ans %= MOD;
        printf("%I64d\n",ans);
    }
}
