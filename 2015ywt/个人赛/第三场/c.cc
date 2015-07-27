#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int cas , e , r , c;
    scanf("%d",&cas);
    while (cas --)
    {
        scanf("%d%d%d",&r , &e ,&c);
        if ( e - c < r)
            puts("do not advertise");
        else if (e - c == r)
            puts("does not matter");
        else puts("advertise");
    }
}
