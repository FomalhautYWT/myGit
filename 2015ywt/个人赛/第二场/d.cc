#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[200][200];
void prepare()
{
    memset(f , -1 , sizeof(f));
}

int dp(int x ,int y)
{
    if ( f[x][y] != -1 ) return f[x][y];
    if ( x == 1 || y == 1 )
    {
        f[x][y] = 1;
        return f[x][y];
    }
    if ( x < 1 || y < 1 )
    {
        f[x][y] = 0;
        return f[x][y];
    }
    if ( x < y )
    {
        f[x][y] = dp(x , x);
        return f[x][y];
    }
    if ( x == y )
    {
        f[x][y] = dp(x , y - 1) + 1;
        return f[x][y] ;
    }
    f[x][y] = dp ( x , y - 1 ) + dp ( x - y , y );
    return f[x][y];
}
int main()
{
    int n;
    prepare();
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",dp(n , n));
    }
}
