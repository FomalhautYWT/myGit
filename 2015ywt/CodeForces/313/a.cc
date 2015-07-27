#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n , a;
    int flag = 0;
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i ++)
    {
        scanf("%d",&a);
        if (a == 1) flag = 1;
    }
    if (flag) puts("-1");
    else puts("1");
}
