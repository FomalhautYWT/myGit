#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
long long f[1000];
long long t[1000];
int main()
{
    f[2] = 1;
    for (int i = 3 ; i <= 20 ; i ++)
    {
        f[i] = (i - 1)*(f[i-1] + f[i-2]);
        //cout <<f[i] << endl;
    }
    t[0] = 1;
    for (int i = 1 ; i <= 20 ; i ++)
    {
        t[i] = t[i - 1]*i;
        //cout << t[i] << endl;
    }
    int n;
    int cas ;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        printf("%.2f%%\n",(double)(100.0*f[n])/(double)(t[n]));
    }

}
