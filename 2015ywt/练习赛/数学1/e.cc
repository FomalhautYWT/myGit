#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long exgcd(long long a ,long long b ,long long &x , long long &y)
{
    if ( b == 0 )
    {
        x = 1 ;
        y = 0 ;
        return a;
    }
    long long r = exgcd(b , a % b , x , y);
    long long t = x;
    x = y ;
    y = t - a / b * y ;
    return r;
}
long long modular_linear(long long a ,long long b ,long long n)
{
    long long d , x , y , e;
    d = exgcd(a , n , x , y);
    if (b % d != 0)
        return -1;
    e = x * ( b / d ) % n + n;
    return e % ( n / d );
}
int main()
{
    while (true)
    {
        long long a , b , c , d , k ;
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k);
        if ( k == 0 && a == 0 && b == 0 && c == 0 )
            break;
        k = 1LL << k;
        d = modular_linear(c , b - a , k);
        if (d == -1)
            puts("FOREVER");
        else
            printf("%lld\n",d);
    }
}
