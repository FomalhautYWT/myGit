#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ans = 1000000000;
int a[200000];
int b[200000];
int n;
int change(int x , int y)
{
    int a = x , b = y;

    int c1[20] , c2[20];
    memset(c1 , 0 , sizeof(c1));
    memset(c2 , 0 , sizeof(c2));
    while (a)
    {
        c1[++c1[0]] = (a & 1);
        a >>= 1;
    }

    while (b)
    {

        c2[++c2[0]] = (b & 1);
        b >>= 1;

    }
    int now = 0;
    for (int i = c1[0] , j = c2[0] ; (i > 0) && (j > 0);i -- , j --)
    {
        if (c1[i] != c2[j]) break;
        now ++;
    }
    return c1[0] + c2[0] - 2 * now;

}
int check(int p)
{
    int ans=0;
    for (int i = 1; i <= n ; i ++)
    {
        ans += change(a[i] , p);
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d",&a[i]);
    for (int i = 1; i <= n ; i ++)
    {
        int now = a[i];
        while (now >= 1)
        {
            if ((now & 1) && (now != 1))
            {
                int nownow = now;
                nownow >>= 1;
                while (nownow <= 100000)
                {
                    nownow <<= 1;
                    b[nownow]++;
                }
            }
            b[now]++;
            now >>= 1;
        }
        now = a[i] << 1;
        while (now <= 100000)
        {
            b[now]++;
            now <<= 1;
        }
    }
    for (int i = 1; i <= 100000 ; i ++)
    {
        if (b[i] == n)
        {
            int now = check(i);
            if (now < ans)
            {
                ans = now;
            }
        }
    }
    printf("%d\n",ans);
}
