#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n ;
void change(int i,int j,int k ,int l ,int &x,int &y,int &z)
{
    if ( j == 1 ) z = i ,         y = k ,         x = l ;
    if ( j == 2 ) z = i ,         y = l ,         x = n + 1 - k ;
    if ( j == 3 ) z = i ,         y = n + 1 - k , x = n + 1 - l;
    if ( j == 4 ) z = i ,         y = n + 1 - l , x = k ;
    if ( j == 5 ) z = l ,         y = k ,         x = n + 1 - i ;
    if ( j == 6 ) z = n + 1 - l  ,y = k ,         x = i;
}

char v[14][14][14];
char cube[14][14][14];

int main()
{
    while(scanf("%d",&n), n)
    {
        getchar();
        for (int i = 1; i <= n ; i ++)
        {
            for (int j = 1; j <= 6 ; j ++)
            {
                for (int k = 1; k <= n ; k ++)
                {
                    scanf("%c",&v[i][j][k]);
                }
                getchar();
            }
        }
        /*for (int i = 1; i <= n ; i ++)
        {
            for (int j = 1; j <= 6 ; j ++)
                for (int k = 1; k <= n ; k ++)
                    cout << v[i][j][k];
            cout << endl;
        }*/
        for (int i = 1; i <= n ; i ++)
            for (int j = 1; j <= n ; j ++)
                for (int k = 1; k <= n ; k ++)
                    cube[i][j][k] = '#';
        for (int i = 1; i <= n ; i ++)
            for (int j = 1 ; j <= 6 ; j ++)
                for (int k = 1 ; k <= n ; k ++)
                    if (v[i][j][k] == '.')
                        for (int l = 1; l <= n ; l ++)
                        {
                            int x , y , z;
                            change(i , j , k , l , x , y , z);
                            cube[x][y][z] = '.' ;
                        }
        while (1)
        {
            bool yes = 1;
            for (int i = 1 ; i <= n ; i ++)
                for (int j = 1; j <= 6 ; j ++)
                    for (int k = 1; k <= n ; k ++)
                        if (v[i][j][k] != '.') 
                            for (int l = 1; l <=  n ; l ++)
                            {
                                int x,y,z;
                                change(i,j,k,l,x,y,z);
                                if (cube[x][y][z] == '.') continue;
                                if (cube[x][y][z] == '#') 
                                {
                                    cube[x][y][z] = v[i][j][k] ;
                                    break;
                                }
                                if (cube[x][y][z] == v[i][j][k]) break;
                                cube[x][y][z] = '.';
                                yes = 0;
                            }
            if ( yes ) break;
        }
        int ans = 0;
        for (int i = 1; i <= n ; i ++)
            for (int j = 1 ; j <= n ; j ++)
                for (int k = 1; k <= n ; k ++)
                    if (cube[i][j][k] != '.')
                        ans ++;
        cout << "Maximum weight: " << ans << " gram(s)" << endl;
    }
}
