#include<iostream>
#include<cstdio>
using namespace std;
long long f[1000];
int n;
int main()
{
    f[0] = 1;
    f[1] = 1;
    scanf("%d",&n);
    for (int i = 2 ; i <= n+2 ; i ++)
    {
        f[i] = f[i-1]+f[i-2];
    }
    cout << f[n+1] - 1 << endl;
}
