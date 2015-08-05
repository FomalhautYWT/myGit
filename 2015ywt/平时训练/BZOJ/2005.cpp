#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
long long euler_phi(int n)
{
    long long m = floor(sqrt(n + 0.5));
    long long ans = n;
    for (int i = 2 ; i <= m ; i ++) if (n % i == 0)
    {
        ans = ans / i * ( i - 1 );
        while ( n % i == 0 )
        {
            n /= i;
        }
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}
int main()
{
    long long n , m;
    long long ans = 0;
    scanf("%lld%lld",&n,&m);
    for (int d = 1 ; d <= min(n , m) ; d ++)
    {
        ans +=(long long) euler_phi(d) * (n / d) * (m / d) ;
    }
    printf("%lld\n",ans * 2 - n * m);

}


/*



*/
