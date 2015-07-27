#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long n , m;
long long lcm(long long a , long long b)
{
    return a / __gcd(a , b) * b;
}
long long a[100];
long long b[100];
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas -- )
    {
        long long ans ;
        scanf("%I64d%d",&n,&m);
        for (int i = 1 ; i <= m ; i ++)
            scanf("%I64d",&a[i]);
        for (int i = 1 ; i <= m ; i ++)
            scanf("%I64d",&b[i]);
        long long now = b[1];
        long long nowlcm = a[1];
        bool flag = true;
        for (int i = 2 ; i <= m ; i ++)
        {
            int j;
        //    cout <<i << " now " << now << endl;
            for (j = 0; j < a[i] ;j ++ , now += nowlcm )
            {
                if (now % a[i] == b[i])
                {
                    nowlcm = lcm(nowlcm , a[i]);
                    break;
                }
            }
          //      cout <<i << " now " << now << endl;
            if (j == a[i]) flag = false;
        }

        if (now < n) {
            ans = 1;
            long long t = n - now;
            ans += t / nowlcm;
        }
        else ans = 0;
        if (ans < 0 ) ans = 0;
        if (!flag) ans = 0;
        printf("%I64d\n",ans);

    }

}
