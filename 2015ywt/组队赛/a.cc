#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void first(int _)
{
    printf("Case %d: first\n",_);
}
void second(int _)
{
    printf("Case %d: second\n",_);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for (int _ = 1; _ <= cas ; _ ++)
    {
        int n ,m;
        scanf("%d%d",&n,&m);
        if ( m == 1 ){
            if ( n & 1 )
                first(_);
            else
                second(_);
            continue;
        }
        else{
            if ( n > m )
                second(_);
            else
                first(_);
        }
    }
}
