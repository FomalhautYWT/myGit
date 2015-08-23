#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
set<long long> s;
long long a[301000];
map<long long,long long> ma;
set<long long>::iterator it,it1,it2;
long long ans = 0;
int main()
{
    long long n , d;
    scanf("%I64d%I64d",&n,&d);

    s.clear();
    ma.clear();
    int last = 0;
    bool yes;
    for (int i = 1; i <= n ; i ++)
    {
        yes = false;
        scanf("%I64d",&a[i]);
        it1 = s.find(a[i] - d);
        if (it1 != s.end())
        {
            it = it1;
            yes = true;
        }
        it2 = s.find(a[i] + d);
        if (it2 != s.end())
        {
            if (it1 != s.end())
            {
                if (ma[a[i]+d] > ma[a[i]-d])
                    it = it2;
                yes = true;
            }
            else{
                it = it2;
                yes = true;
            }
        }
        if (yes && ma[(*it)] > last)
        {
            ans += (ma[(*it)]-last) * (n - i + 1);
            last = ma[(*it)];
        }

        s.insert(a[i]);
        ma[a[i]] = i;
    }
    cout << ans << endl;
}
