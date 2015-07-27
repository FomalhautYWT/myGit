#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n , m;
const int maxN = 10030;
int dfn[maxN] , low[maxN];
int pre[maxN*10] , other[maxN* 10] , last[maxN];
int col[maxN];
int l = 0;
int totID , totCol;
int top , stack[maxN] , instack[maxN];
int d[maxN];
void add_edge(int x , int y)
{
    pre[++l] = last[x] ; last[x] = l ; other[l] = y;
}
int tarjan(int u)
{
    dfn[u] = low[u] = ++ totID;
    instack[u] = true;
    stack[++ top] = u;
    int v;
    for (int p = last[u] ; p != 0; p = pre[p])
    {
        v = other[p];
        if (dfn[v] == 0)
            low[u] = min(low[u] , tarjan(v));
        else if (instack[v])
            low[u] = min(low[u] , dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        ++totCol;
        do{
            v = stack[top --];
            instack[v] = false;
            col[v] = totCol;
        } while (u != v);

    }
    return low[u];
}
void prepare()
{
    memset(pre,0,sizeof(pre));
    memset(other,0,sizeof(other));
    l = 0;
    memset(last , 0 , sizeof(last));
    memset(dfn,0,sizeof(dfn));
    memset(low , 0 , sizeof(low));
    memset(instack , 0 , sizeof(instack));
    memset(stack,0,sizeof(stack));
    totCol = 0;
    totID = 0;
    top = 0;
    memset(d , 0  , sizeof(d));
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        prepare();
        l = 0;
        for (int i = 1; i <= m ; i ++)
        {
            int a, b;
            scanf("%d%d",&a , &b);
            add_edge(a , b);
        }
        for (int i = 1 ; i <= n ; i ++)
            if (!dfn[i]) tarjan(i);

        //for (int i =1 ; i <= n ; i ++ )
         //   cout <<"! " << col[i] << endl;
        if (totCol == 1)
        {
            cout << n << endl;
            continue;
        }
        for (int i = 1; i <= n ; i ++)
        {
            for (int p = last[i] ; p != 0 ; p = pre[p])
                if (col[i] != col[other[p]])
                d[col[i]] = 1;
        }
        int nowA = 0 , nowB = 0;
        for (int i = 1; i <= totCol ; i ++)
            if (d[i])
                nowA ++;
            else nowB ++;
        if ( nowA == totCol - 1 )
        {
            nowA = 0 ;
            for (int i = 1 ; i <= n ; i ++)
                if (col[i] == nowB)
                    nowA ++;
            printf("%d\n",nowA);
        }
        else puts("0");
    }
}
