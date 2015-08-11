#include<iostream>
#include<cstdio>
using namespace std;
const long long MOD =1000000007;
long long quickpow(long long m,long long n,long long k)
{
    long long b = 1;
    while (n > 0)
    {
          if (n & 1)
             b = (b*m)%k;
          n = n >> 1 ;
          m = (m*m)%k;
    }
    return b;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas --)
    {
        long long n;
        scanf("%I64d",&n);
        printf("%I64d\n",quickpow(2,n-1,MOD)%MOD - 1 );
    }
}
