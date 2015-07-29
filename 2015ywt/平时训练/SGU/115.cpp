#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
#include<string>
using namespace std;

int whatday(int d,int m,int y)
{
    int ans;
    if ( m == 1 || m == 2 )
    {
        m += 12;y--;
    }
    if (( y < 1752) || ( y == 1752 && m < 9 ) || ( y == 1752 && m == 9 && d < 3 ))
        ans = ( d + 2 * m + 3 * ( m + 1 ) / 5 + y + y / 4 + 5 ) % 7;
    else 
        ans = ( d + 2 * m + 3 * ( m + 1 ) / 5 + y + y / 4 - y / 100 + y / 400 ) % 7;
    return ans + 1;
}

int main()
{
    int m , d;
    scanf("%d%d",&d,&m);
    if (m < 1 || m > 12)
    {
        puts("Impossible");
        return 0;
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if ( d < 1 || d > 31 )
        {
            puts("Impossible");
            return 0;
        }
    }
    else if ( m == 2 )
    {
        if ( d < 1 || d > 28 )
        {
            puts("Impossible");
            return 0;
        }
    }
    else
    {
        if ( d < 1 || d > 30 )
        {
            puts("Impossible");
            return 0;
        }
    }
    printf("%d\n",whatday(d,m,2001));
}
