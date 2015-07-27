#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if (b == 0)
    {
        x = 1 ;
        y = 0 ;
        return a;
    }
    long long r = exgcd(b , a % b , x , y);
    long long t = x ;
    x = y;
    y = t - a / b * y;
    return r;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas --)
    {
        long long n , b;
        scanf("%I64d%I64d",&n,&b);
        long long x , y;
        exgcd(b , 9973 , x , y);
        long long ans = n * x % 9973;
        while (ans < 0) ans += 9973;
        printf("%I64d\n",ans);
    }
}
