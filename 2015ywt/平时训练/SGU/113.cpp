#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

bool isPr(int p)
{
    for (int i = 2; i*i <= p ; i ++)
    {
        if ( p % i == 0 ) return false;
    }
    return true;
}

int main()
{
    int n , p;
    scanf("%d",&n);
    while ( n -- )
    {
        scanf("%d",&p);
        bool flag = 0;
        for (int i = 2 ; i * i <= p ; i ++)
        {
            if ( p % i == 0 ) 
            if ( isPr( p / i ) )
            {
                flag = 1;
                break;
            }
            else break;
        }
        if ( flag ) cout << "Yes" <<endl;
        else cout << "No" << endl;
    }
}
