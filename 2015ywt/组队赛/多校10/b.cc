#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[51][51];
int main()
{
    a[0][0] = 1;
    for (int i =1 ; i <= 30 ; i ++)
        for (int j = 1; j <= i ; j ++)
        a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    for (int i = 1 ; i <= 30 ; i ++)
    {
        cout << i << " : ";
        long long ans = 1;
        for(int j = 1; j <= i ; j ++)
            ans = ans /__gcd(ans , a[i][j]) * a[i][j];
        cout << ans << endl;
    }
}
