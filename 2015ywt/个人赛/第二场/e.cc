#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
int f[500000];
int op[300000];
int n , m , cas;

void prepare()
{
    for (int i =1 ; i <= n ; i ++)
        f[i] = i;
    memset(op,0,sizeof(op));
}

int root(int p)
{
    if (f[p] == p) return p;
    f[p] = root(f[p]);
    return f[p] ;

}
void combine(int a,int b)
{
    f[root(a)] = root(b);
}
int main()
{
    scanf("%d",&cas);
    while (cas--){
        scanf("%d%d",&n,&m);
        prepare();

        for (int i = 1 ; i <= m ; i ++)
        {
            getchar();
            //cout << i << endl;
            char ch ;
            int a , b;
            scanf("%c %d%d",&ch,&a,&b);
            if (ch == 'D')
            {
                if (op[a]) combine(op[a] , b);
                if (op[b]) combine(op[b] , a);
                op[a] = b;
                op[b] = a;
            }
            else if (ch == 'A')
            {
                if (root(a) == root(op[b]))
                    printf("In different gangs.\n");
                else if (root(a) == root(b))
                    printf("In the same gang.\n");
                else printf("Not sure yet.\n");
            }
        }
    }
}
