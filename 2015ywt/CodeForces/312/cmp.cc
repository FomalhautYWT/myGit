#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
const int n = 10 , s = 1 , t = 10;
int a[n + 1][n + 1];
int main()
{
    srand(time(0));

    printf("%d %d %d\n",n , s , t);
    for (int i = 1; i <= n ; i ++)
    {
        for (int j = 1; j <= i ; j ++){
            if (i == j) a[i][j] = 1;
            else a[i][j] = a[j][i] = rand()% 2;

        }

    }
    for (int i= 1 ; i <= n ; i ++)
    {


        for (int j = 1 ; j <= n ; j ++)
            printf("%d ", a[i][j]);
        puts("");
    }

}
