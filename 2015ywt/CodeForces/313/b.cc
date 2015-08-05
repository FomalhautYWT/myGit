#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a1 , a2 , a3 , b1 , b2 , b3;
    scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3);
    int flag = 0;
    if (a1 >= a2 + a3 && b1 >= b2 && b1 >= b3)
        flag = 1;
    if (a1 >= a2 + b3 && b1 >= b2 && b1 >= a3)
        flag = 1;
    if (a1 >= b2 + a3 && b1 >= a2 && b1 >= b3)
        flag = 1;
    if (a1 >= b2 + b3 && b1 >= a2 && b1 >= a3)
        flag = 1;
    if (b1 >= a2 + a3 && a1 >= b2 && a1 >= b3)
        flag = 1;
    if (b1 >= a2 + b3 && a1 >= b2 && a1 >= a3)
        flag = 1;
    if (b1 >= b2 + a3 && a1 >= a2 && a1 >= b3)
        flag = 1;
    if (b1 >= b2 + b3 && a1 >= a2 && a1 >= a3)
        flag = 1;
    if (flag)
        puts("YES");
    else puts("NO");
    return 0;
}
