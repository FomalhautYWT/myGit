#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int f[20][200][200];
void dp()
{
    for (int i = 0 ; i <= 100 ; i ++)
        for (int j = i ; j <= 100 ; j ++)
            f[1][i][j] = ( i + j ) * ( j - i + 1) / 2;
    //cout << "!!!"<< f[1][0][10] << endl;
    for (int i = 2 ; i <= 10 ; i ++)
        for (int l = 0 ; l <= 100 ; l ++)
            for (int j = 0 ; j <= 100 - l; j ++)
            {
                f[i][j][j + l] = -1;
                for (int s = max(j , 1); s <= j + l ; s ++)
                {
                    if (f[i][j][j + l] == -1 || s + max(f[i -1][j][s-1],f[i][s+1][j+l]) < f[i][j][j + l])
                        f[i][j][j + l] = s + max(f[i -1][j][s-1],f[i][s+1][j+l]);
                }
            }
                //cout << "!!!"<< f[1][0][10] << endl;

}
int main()
{
    int cas , n , m;
    scanf("%d",&cas);
    dp();
    for (int i = 1 ; i <= cas ; i ++)
    {
        scanf("%d%d",&n , &m);
        printf("%d\n",f[n][0][m]);
    }
}
