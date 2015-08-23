#include<cstdio>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int mod=1000000007;
long long f[10005];
int n;
int main()
{
    //freopen("in.txt","r",stdin);;
    f[0]=1;
    for(int i=1;i<=10000;i++)
        for(int j=0;j<i;j++)
            f[i]=((f[j]*f[i-1-j])%mod+f[i])%mod;

    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",f[n]);
    }
    return 0;
}
