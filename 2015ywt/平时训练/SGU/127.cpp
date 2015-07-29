#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cstdlib>
using namespace std;
int n , k , p ;
int a[20] ;
int ans = 0;
int main()
{
    cin >> k >> n ;
    while ( n -- )
    {
        cin >> p ;
        a[p / 1000] ++;
    }
    for (int i = 1 ; i < 10 ; i ++)
    {
        if ( a[i] ) ans += (a[i] - 1) / k + 1;
    }
    cout << ans + 2 << endl;
}
