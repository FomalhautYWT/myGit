#include<iostream>
#include<cstdio>
using namespace std;
long long ans;
long long d[200000];
int main()
{
    int n;
    int x , y;
    scanf("%d",&n);
    for (int i = 1; i <= n - 1 ; i ++)
    {
        scanf("%d%d",&x,&y);
        d[x]++;
        d[y]++;
    }
    for (int i = 1; i <= n ; i ++)
    {
        ans += d[i]*(d[i] - 1)/2;
    }
    cout << ans << endl;


}
