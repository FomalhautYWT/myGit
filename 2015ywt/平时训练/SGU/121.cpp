#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define DEBUG 0
const int maxm = 10086 , maxn = 120 ;
int n ;
int l = - 1;
int d[maxn];
int ma[maxn][maxn];

int c[maxn][maxn];
bool visit[maxn];
void dfs(int x,int color)
{
    color = 3 - color;
    visit[x] = 1;
    for (int y = 1 ; y <= d[x] ; y++)
    {
        if (!c[x][ma[x][y]])
        {
            c[x][ma[x][y]] = c[ma[x][y]][x] = color;
            dfs(ma[x][y] , color);
            color = 3 - color;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
    {
        int p ;
        scanf("%d",&p);
        while (p != 0)
        {
            ma[i][++d[i]] = p;
            scanf("%d",&p);
        }
    }
    
    for (int i = 1 ; i <= n ; i ++)
    {
        if (!visit[i] && (d[i] & 1))
            dfs(i , 1);
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        if (!visit[i])
            dfs(i , 1);
    }
    if (DEBUG) 
    {
        for (int i = 1; i <= n ; i ++)
        cout << " i's v" << visit[i] << endl;
        for (int i = 0 ; i <= l ; i ++)
        {
            cout << " i : " << c[i] << endl;
        }
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        if (d[i] > 1)
        {
            int temp = 0;
            for (int j = 1 ; j <= d[i] ; j ++)
            {
                temp = temp | c[i][ma[i][j]];
            }
            if (temp != 3)
            {
                puts("No solution\n");
                return 0;
            }
        }
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        for (int j = 1; j <= d[i] ; j ++)
        {
            printf("%d ",c[i][ma[i][j]]);
        }
        puts("0");
    }

}
