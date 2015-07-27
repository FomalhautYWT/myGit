#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int ans[1008];
int fir[1008];
int sec[1008];
long long n;
void doit()
{
    long long sum = 0;
    long long ansans = 0;
    long long l = 1;
    long long r = 0;
    int sqr = 0;
    long long sqrtt = (long long )sqrt(n);
    while (1)
    {
        while ( sum < n ){
            r ++;
            sum += r * r;
        }
        if (r > sqrtt) break;
        if (sum == n)
        {
            fir[++ansans] = l;
            sec[ansans  ] = r;
        }
        sum -= l * l;
        ++l;
    }
    printf("%d\n",ansans);
    for (int i = 1 ; i <= ansans ; i ++)
    {
        printf("%d",sec[i] - fir[i] + 1);
        for (int j = fir[i] ; j <= sec[i] ; j ++)
            printf(" %d",j);
        printf("\n");
    }
}
int main()
{
    while (~scanf("%I64d",&n))
    {
        doit();
    }
}
