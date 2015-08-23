#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const long long MOD = 1000000007;
long long inv[200000];
void solve()
{
    inv[1] = 1;
    for (int i = 2; i < 20000 ; i ++)
    {
        inv[i] = ((long long)(MOD - MOD / i) * inv[MOD % i])%MOD;
        //cout << inv[i] << endl;
        //system("pause");
    }
}
long long ans[10004];

int main()
{
    int n;

    solve();
    ans[1] = 1;
    for (long long i = 2; i <= 10000 ; i ++){
        ans[i] = (((ans[i-1] * 2)%MOD  * (2 * i - 1))%MOD *inv[i + 1]) % MOD;
        //if (ans[i] > MOD) cout <<"~~~"<<endl;
        //if (ans[i] < 0 ) cout << i <<" " << ans[i-1]<<" "<<ans[i] <<" " <<inv[i+1]<< endl;
        //system("pause");
    }

    while(scanf("%d",&n) != EOF)
        printf("%lld\n",ans[n]);
}
