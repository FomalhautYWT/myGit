#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std ;
int n , a[4][4] , b[4][4] ;
bool check(int x,int y)
{
    int cnt = 0 ;
    if (x > 1 && a[x-1][y] > a[x][y]) cnt ++;
    if (x < n && a[x+1][y] > a[x][y]) cnt ++;
    if (y > 1 && a[x][y-1] > a[x][y]) cnt ++;
    if (y < n && a[x][y+1] > a[x][y]) cnt ++;
    return (cnt == b[x][y]);
}
void dfs(int x,int y)
{
    if (y == n+1) 
    {
        x++;
        y = 1;
    }
    if (x == n+1)
    {
        for(int i = 1 ; i <= n ; i ++)
        if (!check(n,i)) return;
        for (int i = 1; i <= n ; i ++)
        {
            printf("%d",a[i][1]);
            for (int j = 2 ; j <= n ; j ++)
            {
                printf(" %d",a[i][j]);
            }
            puts("");
        }
        exit(0);
    }
    for (int i = 0 ; i < 10 ; i ++)
    {
        a[x][y] = i;
        if (x==1 || check(x-1,y)) dfs(x,y+1);
    }
}
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
    {
        for(int j = 1; j <= n ; j ++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    dfs(1 , 1);
    puts("NO SOLUTION");
    return 0;
}
