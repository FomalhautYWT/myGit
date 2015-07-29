#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int a[2000];

int f(int x)
{
    return ((x - 1) % 9) + 1;
}

int main()
{
    int testCase;
    scanf("%d",&testCase);
    while (testCase--)
    {
        int n ;
        scanf("%d",&n);
        for (int i = 1 ; i <= n ; i ++)
        {
            scanf("%d",&a[i]);
            a[i] = f(a[i]);
        }
        int ans = 0;
        for (int i = n; i > 0 ; i --)
        {
            int temp = 1;
            for (int j = 1;j <= i ; j ++)
            {
                temp *= a[j] ;
                temp = f(temp);
            }
            ans += temp;
            ans = f(ans);
        }
        printf("%d\n",ans);
    }
}
