#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[2000];
int main()
{
    int n;
    scanf("%d",&n);
    bool ans = false;
    for (int i = 1; i <= n ; i ++)
        scanf("%d",&a[i]);
    for (int i = 1; i <= n + 1 ; i ++)
    {
        for (int j = 1; j <= n ; j ++)
        {
            if (j & 1) a[j] = (a[j] + 1) % n;
            else a[j] = (a[j] + n - 1) % n;
        }
        bool flag = true;
        if (a[1]) {
            flag = false;
            continue;
        }
        for (int j = 2; j <= n ; j ++)
        {
            if (a[j] != a[j - 1] + 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans = true;
        }
    }
    if (ans == false)
        puts("No");
    else puts("Yes");
}
