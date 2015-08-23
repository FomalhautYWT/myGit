#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int x[100],y[100],z[100];
bool yes[20][3][20][3];
int n;
int nowans;
int last;
int v[20];
bool check(int a ,int b ,int c ,int d)
{
    int x1 , x2 ,y1 , y2;
    if ( b == 0 )
        x1 = x[a] , y1 = y[a];
    if ( b == 1 )
        x1 = y[a] , y1 = z[a];
    if ( b == 2 )
        x1 = x[a] , y1 = z[a];
    if ( d == 0 )
        x2 = x[c] , y2 = y[c];
    if ( d == 1 )
        x2 = y[c] , y2 = z[c];
    if ( d == 2 )
        x2 = x[c] , y2 = z[c];
    if (x1 >= x2 && y1 >= y2) return true;
    if (x1 >= y2 && y1 >= x2) return true;
    return false;
}
void dfs(int p , int mian ,int deep)
{

    if (deep > nowans) nowans = deep;
    if (last == 0) return;
    for (int i = 1; i <= n ; i ++)
    {
        bool flag = false;
        for (int j = 0 ; j<= 2 ; j ++)
            if (yes[p][mian][i][j] && v[i])
            {
                flag = true;
                v[i] = false;
                last --;
                dfs(i,j,deep+1);
                v[i] = true;
                last ++;
            }
        if (flag = false){
            v[i] = false;
            last --;
        }

    }
}
void prepare()
{
    for (int i = 1; i <= n ; i ++)
        for (int j = 0 ; j <= 2 ; j ++)
        for (int k = 1; k <= n ; k ++)
        for (int l = 0 ; l <= 2 ; l ++)
        if (check(i,j,k,l))yes[i][j][k][l] = true;
    else yes[i][j][k][l] = false;
    nowans = 0;
    for (int i =1 ; i <= n ; i ++)v[i] = 1;
}
int main()
{

    int _ = 1;
    while(scanf("%d",&n),n)
    {
        for (int i = 1; i <= n ; i ++)
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
        prepare();
        for (int i = 1; i <= n ; i ++)
        {
            v[i] = false;
            last = n - 1;
            for (int j = 0 ; j <= 2 ; j ++)
                dfs(i,j,1);
            v[i] = true;
            last = n;
        }
        printf("Case %d: %d\n",_++,nowans);
    }
}
