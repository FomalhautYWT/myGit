#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int sg[100000];
int b [1000];
int now[100000];
int k ;
int getSG()
{
    sg[0] = 0;
    for (int i = 1; i <= 10000 ; i ++)
    {
        memset(b , 0 , sizeof( b ));
        for (int j = 1 ; j <= k ; j ++)
            if ( i >= now[j] ) b[sg[i - now[j]]] = true;
        int j ;
        for (j = 0 ; j < 101 ; j ++) if ( b[j] == false )
            break;
        sg[i] = j;
    }

}
int main()
{
    int p , m , sto;
    while (scanf("%d",&k))
    {
        if ( k == 0 ) break;
        int nowAns;
        memset(sg , 0 , sizeof(sg));
        for (int i = 1; i <= k ; i ++)
        {
            scanf("%d",&now[i]);
        }
        getSG();
        scanf("%d",&p);
        for (int q = 1 ; q <= p ; q ++)
        {
            nowAns = 0;
            scanf("%d",&m);
            for (int i = 1; i <= m ; i ++)
            {
                scanf("%d",&sto);
                nowAns ^= sg[sto];
            }

            if (nowAns == 0) printf("L");
            else printf("W");
        }
        puts("");
    }
}
