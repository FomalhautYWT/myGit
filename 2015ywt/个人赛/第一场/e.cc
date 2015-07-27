#include<iostream>
#include<cstdio>
using namespace std;
int n, m;
int f[500000];
int a[500000];
int b[500000];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n ; i ++)
        scanf("%d%d",&a[i],&b[i]);
    for (int i = 1; i <= n ; i ++)
        for (int j = m ; j >= a[i] ; j --)
        if (f[j] < f[j - a[i]] + b[i])
        f[j] = f[j - a[i]] + b[i];
    cout << f[m];
}
