#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct node{
    int p,a;
}p[2000];
const bool cmp (node a,node b)
{
    return a.p < b.p;
}
int main()
{
    int n , ans = 0;
    int d0 = 0 , d1 = 0;
    scanf("%d",&n);
    for (int i = 1;i <= n ; i ++)
    {
        scanf("%d%d",&p[i].p,&p[i].a);
        if (p[i].p > 0) d0 ++;
        else  d1 ++;
    }
    sort(p+1,p+n+1,cmp);
    //cout << d0 << d1 << endl;
    if (d0<d1)
    {
        for (int i = n ; i > n - 2 * d0 - 1; i -- )
            ans += p[i].a;
    }
    else if (d0 > d1){
        for (int i = 1 ; i <=  2 * d1 + 1 ; i ++)
            ans += p[i].a;
    }
    else {
        for (int i = 1; i <= n ; i ++)
            ans += p[i].a;
    }
    //for (int i = 1; i <= n ; i ++)
    //    printf("%d %d\n",p[i].p,p[i].a);
    cout << ans << endl;
}
