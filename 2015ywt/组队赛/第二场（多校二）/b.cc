#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int suan(int x,int y)
{
    if ( y & 1 ) y ++;

    return min(x , y >> 1);
}
int ans1 , ans2 ,ans3 , ans4,ans5,ans6,ans7,ans8,ans9,ans10,ans11,ans12,ans13,ans14,ans15,ans16;
int ansc1 , ansc2 , ansd1 , ansd2;
int ansa,ans22,ans33,ans44;
int n , m , x , y;
int ansaa;
int ans;

int max(int a,int b,int c,int d)
{
    int ans = a;
    ans = max( ans , b);
    ans = max( ans , c);
    ans = max( ans , d);
    return ans ;
}

int min(int a,int b,int c,int d)
{
    int ans = a;
    ans = min( ans , b);
    ans = min( ans , c);
    ans = min( ans , d);
    return ans ;
}

int qiu1(int x,int y,int n ,int m)
{
    int p = min(x - 1 , y);
    int q = y - 1;
    int r = min(m - y , x);
    int l = suan(n - x , m);
    return max(p , q, r , l);

}
int qiu2(int x,int y,int n ,int m)
{
    int p = min(x , y - 1);
    int q = x - 1;
    int r = min(m - y , x);
    int l = suan(n - x , m);
    return max(p , q, r , l);
}
int qiu3(int x,int y,int n ,int m)
{
    int p = min(y - 1 , x );
    int q = min(m - y + 1 , x - 1);
    int r = m - y;
    int l = suan(n - x , m );
    return max(p , q , r , l);
}


int main()
{
    while (scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)
    {
        ans = ~0u >> 1;
        ans1 = min(x , y - 1);
        ans2 = min(n - x , y);
        ans3 = min(m - y + 1 , x - 1);
        ans4 = min(n - x + 1 , m - y);
        ansa = max(ans1 , ans2);
        ansa = max(ansa , ans3);
        ansa = max(ansa , ans4);

        //cout << "1: " << ansa << endl;

        ans5 = (x - 1 , y);
        ans6 = (x , m - y);
        ans7 = (n - x + 1 , y - 1);
        ans8 = (n - x , m - y + 1);
        ans22 = max(ans5 , ans6);
        ans22 = max(ans22 , ans7);
        ans22 = max(ans22 , ans8);

        //cout << "2: " << ans22 << endl;

        ans9 = suan(x - 1 , m);
        ans10 = suan(n - x , m);
        ans11 = y - 1;
        ans12 = m - y;
        ans33 = max(ans9,ans10);
        ans33 = max(ans33,ans11);
        ans33 = max(ans33,ans12);

        //cout << "3: " << ans33 << endl;

        ans13 = suan(y - 1, n);
        ans14 = suan(m - y , n);
        ans15 = x - 1;
        ans16 = n - x;
        ans44 = max(ans13,ans14);
        ans44 = max(ans44 , ans15);
        ans44 = max(ans44 , ans16);

        if (((x == 1) || (x == n)) && ((y != 1) && (y != m)))
        {
            x = 1;
            ansc1 = min(n - x , m - y + 1);
            ansc1 = max(ansc1,suan(y - 1,n));
            ansc2 = min(y , n - x);
            ansc2 = max(ansc2,suan(m - y , n));
            ans = min(ans , ansc1);
            ans = min(ans , ansc2);
        }
        if (((y == 1) || (y == m)) && ((x != 1) && (x != n)))
        {
            y = 1;
            ansd1 = min(n - x + 1 , m - y);
            ansd1 = max(ansd1 , suan(x - 1 , m));

            ansd2 = min(x , m - y);
            ansd2 = max(ansd2 , suan(n - x , m));
            ans = min(ans , ansd1);
            ans = min(ans , ansd2);
        }
        if ((x == 1 || x == n) && (y == 1 || y == m ))
        {
            ansaa = suan(n - 1 , m);
            ansaa = min(ansaa ,suan(m - 1 , n));
            ans = min(ans , ansaa);
        }
        int fxz1=qiu1(x,y,n,m);
        fxz1=min(fxz1,qiu1(y,n-x+1,m,n),qiu1(n-x+1,m-y+1,n,m),qiu1(m-y+1,x,m,n));
        int fxz2=qiu2(x,y,n,m);
        fxz2=min(fxz2,qiu2(y,n-x+1,m,n),qiu2(n-x+1,m-y+1,n,m),qiu2(m-y+1,x,m,n));
        int fxz3=qiu3(x,y,n,m);
        fxz3=min(fxz3,qiu3(y,n-x+1,m,n),qiu3(n-x+1,m-y+1,n,m),qiu3(m-y+1,x,m,n));



        ans = min(ans , ansa);
        ans = min(ans ,ans22);
        ans = min(ans , ans33);
        ans = min(ans , ans44);
        ans=min(ans,fxz1,fxz2,fxz3);
        if (m == 1 || n == 1)
            ans = 1;
        printf("%d\n",ans);
    }
}
