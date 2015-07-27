#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
long long l , r , h , q , deep , ok;
vector < pair<long long , long long > > vc;
const int INF = ~0u >> 1;
int main()
{
    scanf("%I64d%I64d",&h,&q);
    for( int i = 1 ; i <= q ; i ++)
    {
        long long deep , l , r , ok;
        scanf("%I64d%I64d%I64d%I64d",&deep , &l , &r , &ok);
        l = l << (h - deep) ;
        r = ( r << ( h - deep ) ) + ( 1LL << ( h - deep ) ) - 1;
        if (ok == 0)
        {
            vc.push_back(pair<long long , long long> (l , r));
        }
        else
        {
            vc.push_back(pair<long long ,long long> (1LL << (h - 1), l - 1));
            vc.push_back(pair<long long ,long long> (r + 1, (1LL << h) - 1));

        }
    }
    vc.push_back(pair<long long , long long> ((1LL << (h - 1)) - 1, (1LL << (h - 1)) - 1));
    vc.push_back(pair<long long , long long> ( (1LL << h), (1LL << h)));


    sort(vc.begin(),vc.end());
    int sz = vc.size();
    int cnt = 0;
    long long ans = -1;
    long long far = 0;
    for (int i = 0 ; i < vc.size() - 1 ; i ++)
    {
        //cout << vc[i].first << " " << vc[i].second << endl;
        far = max(far , vc[i].second);
        long long u = max(vc[i].second,far) + 1;
        long long v = vc[i + 1].first - 1;
        if (v > far && u <= v)
        {
            cnt ++ ;
            if ( u == v ) ans = u;
        }
    }
    if (cnt == 0)
        printf("Game cheated!\n");
    else if (cnt == 1 && ans != -1)
        printf("%I64d\n",ans);
    else
        printf("Data not sufficient!\n");

}
