#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    int ans = (n - 1) * 2;
    ans -= (k - 1);
    for (int i = 1; i <= k ; i ++)
    {
        int m;
        scanf("%d",&m);
        int last = -8;
        for (int j = 1 ; j <= m ; j ++)
        {
            int  a;
            scanf("%d",&a);
            if (a == j && j != 1)
                ans -= 2;
            last = a;
        }
    }
    printf("%d\n",ans);
}
