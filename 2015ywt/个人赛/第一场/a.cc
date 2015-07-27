#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int disx[4] = {0 , 1 , 0 , -1};
int disy[4] = {1 , 0 , -1 , 0};
int quex[10000];
int quey[10000];
int v[200][200];
int a[200][200];
int n , m;
int bfs(int x, int y)
{
    int l = 0 , r = 1;
    quex[1] = x;
    quey[1] = y;
    v[x][y] = 1;
    int ans = 1;
    while (l != r)
    {
        int nowx = quex[++l];
        int nowy = quey[l];
        for (int i = 0 ; i < 4 ; i ++)
        {
            int dx = nowx + disx[i];
            int dy = nowy + disy[i];
            if (dx < 1 || dx > n) continue;
            if (dy < 1 || dy > m) continue;
            if (v[dx][dy] || a[dx][dy]) continue;
            if (!v[dx][dy] && a[dx][dy] == 0)
            {
                quex[++r] = dx;
                quey[r]   = dy;
                v[dx][dy] = 1;
                ans ++;

            }
        }
    }
    return ans;
}
int main()
{

    while (scanf("%d%d",&m,&n))
    {
        if (m == 0 && n == 0) break;
        memset(a,0,sizeof(a));
        memset(quex,0,sizeof(quex));
        memset(quey,0,sizeof(quey));
        memset(v,0,sizeof(v));
        int sti , stj;
        getchar();
        for (int i = 1; i <= n ; i ++)
        {
            for (int j = 1; j <= m ; j ++)
            {
                char c = getchar();
                //cout << c ;
                if (c == '.')
                    a[i][j] = 0;
                else if (c == '#')
                    a[i][j] = 1;
                else {
                    a[i][j] = 0;
                    sti = i;
                    stj = j;
                   // cout << i << " " << j << endl;
                }
            }
            char c = getchar();
            //cout << c;
        }
        cout << bfs(sti , stj) << endl;


    }

}


