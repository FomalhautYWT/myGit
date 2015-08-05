#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[9997];
struct node
{
    long long x,y;
}bl[3000];

bool cmp(node a ,node b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
long long inv[300000];
void solve(long long m)
{
    inv[1] = 1;
    for (long long i = 2; i <= m ; i ++)
    {
        inv[i] = ((long long)(MOD - MOD / i) * (inv[MOD % i])) %MOD;
    }
}
long long ifact[400000];
long long fact[400000];
void fac(long long m)
{
    memset(ifact,0,sizeof(ifact));
    memset(fact ,0,sizeof(fact));
    ifact[0] = fact[0] = 1;
    for (int i = 1; i <= m ; i ++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        ifact[i] = ifact[i - 1] * inv[i] % MOD;
    }

}
long long C(long long x, long long y)
{
    if(x<y || x<0 || y<0)return 0;
    return (long long)fact[x]*(((long long)ifact[x-y]*ifact[y])%MOD)%MOD;
}

int main()
{
    solve(300000);
    fac(300000);

    long long n , m , k;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    for (long long i = 1 ; i <= k ; i ++)
    {
        scanf("%I64d%I64d",&bl[i].x,&bl[i].y);
    }
    bl[k + 1].x = n;
    bl[k + 1].y = m;
    sort(bl + 1 , bl + k + 2 , cmp);
    for (long long i = 1 ; i <= k + 1 ; i ++)
    {

        dp[i] = C(bl[i].x + bl[i].y - 2, bl[i].x - 1) % MOD;
        //cout << bl[i].x << " " << bl[i].y << dp[i] << endl;
        for (long long j = 1; j < i ; j ++)
        {
            if (bl[j].y <= bl[i].y)
            {
                dp[i] -= dp[j] * C(bl[i].x - bl[j].x + bl[i].y - bl[j].y,bl[i].x - bl[j].x);
                dp[i] %= MOD;
                if (dp[i] < 0) dp[i] += MOD;
            }
        }
    }
    //for (int i = 1 ; i <= k + 1; i ++)
    //cout << dp[i] << endl;

    printf("%I64d\n",dp[k + 1]);

}
