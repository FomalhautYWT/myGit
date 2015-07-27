#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int main()
{
    int n;
    int d1 = 0 , d0 = 0 ;
    scanf("%d",&n);
    getchar();
    for (int i = 1; i <= n ; i ++)
    {
        int p = getchar() - '0';
        if (p) d1 ++;
        else d0 ++;
    }
    printf("%d\n",n - min(d1 , d0) * 2);

}
