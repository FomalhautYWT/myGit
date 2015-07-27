#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double f[200000];
int map[200000];
int n , m;
void prepare()
{
    memset(map, -1 , sizeof(map));
    memset(f,0,sizeof(f));
}
void solve()
{
    for (int i = n - 1 ; i >= 0 ; i --)
    {
        if (map[i]!=-1)
        {

            f[i] = f[map[i]];

        }
        else{
        for (int j = 6 ; j >= 1; j --)
            f[i] += f[i + j];
        f[i] = f[i] / 6 + 1;
        }
       // cout <<i << " "<<  f[i] << endl;

    }
    //for (int i = 0 ; i <= n ; i ++ )
     //   cout << f[i] << endl;
    printf("%.4f\n",f[0]);
}
int main()
{

    while (scanf("%d%d",&n,&m))
    {
        prepare();
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= m ; i ++)
        {
            int x, y;
            scanf("%d%d",&x , &y);
            map[x] = y;
        }
        solve();
    }
    return 0;
}
