#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double INF = 1e10* 1.0;
double ans;
struct point{
    double x , y;
}po[333][333];
int p[333];
int n ;
double f[333][333];
double dist(point a , point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void prepare(int x)
{
    for (int i = 1; i <= n ; i ++)
        for (int j = 1 ; j <= p[i] ; j ++)
            f[i][j] = INF;
    for (int i = 1 ; i <= p[2] ; i ++)
        f[2][i] = dist(po[1][x] , po[2][i]);
}
void dp(int x)
{
    for (int i = 3 ; i <= n ; i ++)
        for (int j = 1 ; j <= p[i] ; j ++)
            for (int k = 1 ; k <= p[i - 1] ; k ++)
                f[i][j] = min(f[i][j],dist(po[i-1][k],po[i][j])+f[i-1][k]);
    for (int i = 1; i <= p[n] ; i ++)
        f[1][x] = min(f[1][x],dist(po[1][x],po[n][i])+f[n][i]);
}
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
    {
        scanf("%d",&p[i]);
        for (int j = 1 ;j <= p[i] ; j ++)
            scanf("%lf%lf",&po[i][j].x,&po[i][j].y);
    }
    ans = -1;
    for (int i = 1 ; i <= p[1] ; i ++)
    {
        prepare(i);
        dp(i);
        if (ans == -1 || ans > f[1][i])
            ans = f[1][i];
    }
    ans *= 100.0;
    int nowAns = (int) ans;
    printf("%d\n",nowAns);
}
