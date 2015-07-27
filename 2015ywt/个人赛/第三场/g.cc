#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int cas;
int n , m , ro;
long long tr[50000];
int lowbit(int t)
{
    return t & (-t);
}
void update(int x, long long num)
{
    while (x <= m)
    {
        tr[x] += num;
        x += lowbit(x);
    }
}
long long getsum(int x)
{
    long long ans = 0;
    while ( x > 0)
    {
        ans += tr[x] ;
        x -= lowbit(x);
    }
    return ans;
}
vector < pair < long long , long long > > vc;
int main()
{
    scanf("%d",&cas);
    for (int _ = 1 ; _ <= cas ; _ ++)
    {
        memset(tr,0,sizeof(tr));
        long long ans = 0;
        vc.clear();

        scanf("%d%d%d",&n,&m,&ro);
        for(int i = 1; i <= ro ; i ++)
        {
            int a , b;
            scanf("%d%d",&a , &b);
            vc.push_back(make_pair(a , b));
        }
        sort(vc.begin()  , vc.end());

        for (int i = 0 ; i < vc.size() ; i ++)
        {

            update(vc[i].second , 1);
            ans += getsum( m );
            ans -= getsum( vc[i].second );
        }

        printf("Test case %d: %lld\n",_ , ans);
    }
}
