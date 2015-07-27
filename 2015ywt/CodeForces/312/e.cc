#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int sum[27][300000];
int len , q;
int limit;
int ans [666660];
int flag[27][300000];
void pushDown(int a,int x,int ll ,int rr)
{
    int mid = ll + rr >> 1 ;
    if (flag[a][x] != -1)
    {
        sum[a][x << 1] = (mid - ll + 1) * flag[a][x];
        sum[a][x << 1 | 1] = (rr - mid) * flag[a][x];
        flag[a][x << 1] = flag[a][x];
        flag[a][x << 1 | 1] = flag[a][x];
        flag[a][x] = -1;
    }
}
void update(int a,int x,int ls , int rs)
{
    sum[a][x] = sum[a][ls] + sum[a][rs];
}
void insert(int a,int x,int ll,int rr,int l,int r,int d)
{
    int ls = x << 1 , rs = ls | 1 , mid = ll + rr >> 1;
    if ( l == ll && rr == r )
    {
        sum[a][x] = d * (rr - ll + 1);
        flag[a][x] = d;
        return;
    }
    pushDown(a , x , ll , rr);
    if ( r <= mid ) insert(a , ls , ll , mid , l , r , d);
    else if ( l > mid ) insert(a , rs , mid + 1 , rr , l , r , d);
    else{
        insert(a , ls , ll , mid , l , mid , d);
        insert(a , rs , mid + 1 , rr , mid + 1 , r , d);
    }
    update(a , x , ls , rs);
}
int quary(int a, int x, int ll ,int rr ,int l , int r)
{
    int ls = x << 1 , rs = ls | 1 , mid = ll + rr >> 1;
    if (l == ll && rr == r)
    {
        return sum[a][x];
    }
    pushDown(a , x , ll , rr);
    int ans ;
    if ( r <= mid ) ans = quary(a , ls , ll , mid , l , r);
    else if ( l > mid ) ans = quary(a , rs , mid + 1 , rr  , l , r);
    else {
        ans =  quary ( a , ls , ll , mid , l , mid ) + quary ( a , rs , mid + 1 , rr , mid + 1 , r );
    }
    update(a , x , ls , rs);
    return ans;
}
void printStr()
{
    for (int i = 1; i <= len ; i ++)
        for (int j = 1 ; j <= 26 ; j ++)
        {
            if (quary(j , 1 , 1 , limit , i , i ) ){
                ans[i] = j;
                //cout <<" i j " << i << " " << j <<endl;
            }
        }
    for (int i = 1 ; i <= len ; i ++)
        printf("%c",ans[i] + 'a' - 1);
    puts("");
}

int main()
{
    scanf("%d%d",&len , &q);
    getchar();
    limit = 1;
    memset(flag , -1 , sizeof(-1));
    while ( limit < len ) limit <<= 1;
    for (int i = 1 ; i <= len ; i ++)
    {
        int a = getchar() - 'a' + 1;
        insert(a , 1 , 1 , limit , i , i , 1);
    }
    for (int i = 1; i <= q ; i ++)
    {
        //printStr();
        int l , r, c;
        scanf("%d%d%d",&l,&r,&c);
        int now = 0;
        if ( c == 0 )
        {
            for (int j = 1; j <= 26 ; j ++)
            {
                //cout << "j = " << j << endl;
                int cnt = quary(j , 1 , 1 , limit , l , r);
                //cout << "1 : " << l  <<" " << r <<" "<< cnt <<endl;
                if (cnt == 0) continue;
                //cout << "2 : " << l  <<" " << r <<endl;
                insert(j , 1 , 1 , limit , l , r , 0);
                //cout << quary(j , 1 , 1 , limit , 7 , 7) << endl;
                //cout << quary(j , 1 , 1 , limit , 8 , 8) << endl;
                //cout << quary(j , 1 , 1 , limit , 7 , 9) << endl;
                //cout << quary(j , 1 , 1 , limit , 7 , 10) << endl;
                //cout << "3 : " << r - now - cnt + 1 <<" " << r - now <<endl;
                insert(j , 1 , 1 , limit , r - now - cnt + 1 , r - now , 1);
                now += cnt;
                //printStr();
            }
        }
        else
        {
            for (int j = 1 ; j <= 26 ; j ++)
            {
                //cout << "j = " << j << endl;
                int cnt = quary(j , 1 , 1 , limit , l , r);
                //cout << "1 : " << l  <<" " << r <<" "<< cnt <<endl;

                if (cnt == 0) continue;
                //cout << "2 : " << l  <<" " << r <<endl;
                insert(j , 1 , 1 , limit , l , r , 0);
                //cout << "3 : " << l + now  <<" " << l + now + cnt - 1 <<endl;
                insert(j , 1 , 1 , limit , l + now , l + now + cnt - 1, 1);
                now += cnt;
            }
        }

    }
    printStr();
}
