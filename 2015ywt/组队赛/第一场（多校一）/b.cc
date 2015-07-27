#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
using namespace std;
set< pair<int , int > > s;
int n , k;
int a[300000];
int last ;
long long ans;
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas --)
    {
        scanf("%d%d",&n,&k);
        for (int i = 1; i <= n ; i ++)
            scanf("%d",&a[i]);
        last = 1;
        ans = 0;
        s.clear();
        for (int i = 1; i <= n ; i ++)
        {
            while ( (!s.empty()) && abs( s.begin()->first - a[i]) >= k )
            {
                pair <int ,int > p = (*s.begin());
                s.erase(p);
                last = max(last , p.second + 1);
            }
            while ( (!s.empty()) && abs( s.rbegin()->first - a[i])  >= k)
            {
                pair< int ,int > p = (*s.rbegin());
                s.erase(p);
                last = max(last , p.second + 1);
                //cout << p.first << " " << p.second<<endl;
            }

            ans += i - last + 1;
            s.insert(make_pair(a[i],i));

            //cout << last << " " << s.size() <<endl;
        }
        printf("%I64d\n",ans);
    }
}
