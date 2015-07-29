#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int cas;
    scanf("%d",&cas);
    for (int _ = 1 ; _ <= cas ; _ ++)
    {
        long long n , m;
        scanf("%I64d%I64d",&n,&m);
        long long tmp = 1;
        long long x = 0;
        while (tmp < n)
        {
            tmp *= m;
            x ++;
        }
        long long gcd1 = __gcd(tmp , n);
        tmp /= gcd1;
        n /= gcd1;
        gcd1 = __gcd(x , n);
        x /= gcd1;
        n /= gcd1;
        tmp *= x;
        printf("Case %d: %I64d/%I64d\n",_,tmp,n);
    }

}
