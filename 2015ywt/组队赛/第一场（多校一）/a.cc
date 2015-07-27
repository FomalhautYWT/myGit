#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
const int MOD = 1e9 + 7;
long long n , b[200000];
long long a[200000];
long long l[200000] , r[200000];
long long ans;
int main()
{
    //freopen("1001.in","r",stdin);
    //freopen("1001.out","w",stdout);
    while (scanf("%I64d",&n)!=EOF)
    {
        ans = 0;
        memset(b,0,sizeof(b));
        memset(l,0,sizeof(l));
        for (int i = 1; i <= n ; i ++)
        {
            scanf("%I64d",&a[i]);
            for (int j = 1; j * j <= a[i] ; j++)
                if (a[i] % j == 0){
                    l[i] = max(l[i],b[j]);
                    l[i] = max(l[i],b[a[i]/j]);
                }

            l[i] = max(l[i] , b[a[i]]);
            b[a[i]] = i;
        }
        for (int i = 1; i <= 100007; i ++)
        {
            b[i] = n + 1;
            r[i] = n + 1;
        }

        for (int i = n ; i >= 1 ; i --)
        {
            for (int j = 1 ; j*j <= a[i] ; j ++)
                if (a[i] % j == 0)
                {
                    r[i] = min(r[i] , b[j]);
                    r[i] = min(r[i] , b[a[i]/j]);
                }

            r[i] = min(r[i] , b[a[i]]);
            b[a[i]] = i;
        }
        //for (int i = 1; i <= n ; i ++)
          //  cout << l[i] << " " << r[i] << endl;
        for (int i = 1; i <= n ; i ++)
        {
            ans += (long long)(i - l[i]) % MOD *(long long) (r[i] - i) % MOD;
            ans %= MOD;
        }
        printf("%I64d\n",ans);
    }
    //fclose(stdin);
    //fclose(stdout);
}
