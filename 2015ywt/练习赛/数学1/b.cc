#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long lcm(long long x ,long long y)
{
    return (x / __gcd(x , y) * y);
}
long long ans , a;
int n , cas;
int main()
{
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d",&n);
        ans = 1;
        for (int i = 1; i <= n ; i ++)
        {
            scanf("%I64d",&a);
            ans = lcm(a , ans);
        }
        printf("%I64d\n",ans);
    }
}
