#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t , s , q;
    int ans = 0;
    scanf("%d%d%d",&t,&s,&q);
    while(s < t)
    {
        s *= q;
        ans ++;
    }
    cout << ans <<endl;
}
