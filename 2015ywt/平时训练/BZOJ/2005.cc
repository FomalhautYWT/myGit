#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long f[200020];
int main()
{
    long long n, m;
    scanf("%lld%lld",&n,&m);
    long long ans = 0;
    for (int i = min(n , m) ; i >= 1 ; i --)
    {
        f[i] = (n / i) * (m / i);
        for (int j  = 2 ; j <= n / i && j <= m / i ; j ++)
            f[i] -= f[i * j];
        ans += f[i] * ( i * 2 - 1 );
    }
    printf("%lld\n",ans);

}
