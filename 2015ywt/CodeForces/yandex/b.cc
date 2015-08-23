#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n ;
const long long INF = 10000000000000000LL;
long long a[500000];
long long f[500000];
int min(long long a , long long b , long long c)
{
    return min(a , min(b , c));
}
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
        scanf("%I64d",&a[i]);
    sort(a + 1 , a + n + 1);
    f[0] = 0;
    for (int i = 1 ; i <= n ; i ++)
    {
        f[i] = INF;
        if (i > 1)
        {
            f[i] = min(f[i],f[i - 2] + a[i] - a[i - 1]);
        }
        if (i > 2)
        {
            int tmp = min(a[i]-a[i-2] , a[i] * 2 - a[i - 1] - a[i - 2],a[i] + a[i - 1] - a[i - 2] * 2);
            f[i] = min(f[i],f[i - 3] + tmp);
        }
        //cout << f[i] <<endl;
    }


    printf("%I64d\n",f[n]);
}
