#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a , b , p , tempa , tempb;
int gcd(int a, int b )
{
    if ( b == 0 ) return a;
    return gcd ( b , a % b );
}
int main()
{
    scanf("%d%d",&a , &b);
    int p = 0;
    while ( a != 0 && b != 0 )
    {
        int tempa , tempb;
        tempa = a / gcd(a,b);
        tempb = b / gcd(a,b);
        a = tempa;
        b = tempb;
        if ( a + b & 1) 
        {
            cout << -1 << endl;
            return 0;
        }

        p ++;
        if ( a < b ) swap ( a , b );
        tempa = a - b ;
        tempb = b * 2 ;
        a = tempa ;
        b = tempb ;
    }
    cout << p  << endl; 
}

