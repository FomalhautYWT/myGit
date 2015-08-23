#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;
map <long long , long long> ho , qi;
long long n , k  ,ans = 0;
long long a[300000];
int main()
{
    scanf("%I64d%I64d",&n,&k);
    for (int i = 1 ; i <= n ; i ++)
    {
        scanf("%I64d",&a[i]);
        ho[a[i]] ++;
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        ho[a[i]]--;
        if (a[i] % k == 0)
        {
            ans += ho[a[i] * k] * qi[a[i] / k];
        }
        qi[a[i]]++;
    }
    printf("%I64d\n",ans);
}
