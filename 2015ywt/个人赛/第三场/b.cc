#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n , m ;
int used[1000];
int link[1000];
int cha[700][700];
bool hungry(int p)
{
    for (int i = 1 ; i <= n ; i ++)
        if (!used[i] && cha[p][i])
        {
            used[i] = 1;
            if (link[i] == -1 || hungry(link[i]))
            {
                link[i] = p;
                return true;
            }
        }
    return false;
}
int ans = 0;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n ; i ++)
        link[i] = -1;
    for (int i = 1; i <= m ; i ++)
    {
        int a, b;
        scanf("%d%d",&a , &b);
        cha[a][b] = 1;
    }
    for (int i = 1; i <= n ; i ++)
    {
        memset(used , 0 , sizeof(used));
        if (hungry(i)) ans ++;
    }
    printf("%d\n",ans);
}
