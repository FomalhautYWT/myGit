#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct island
{
    long long l , r;

    bool operator < (island il)
    {
        return l < il.l;
    }
};
bool cmp1(island a,island b)
{
    return a.l < b.l;
}
struct kong
{
    long long nth , l , r , ans;
    bool operator < (kong & kn)
    {
        if (r == kn.r) return l < kn.l;
        return r < kn.r;
    }
    void print()
    {
        cout << l <<" " << r << " " << nth << " " << ans << endl;
    }
};
struct bridge
{
    long long nth , len;
    bridge(){}
    bridge(long long _len , long long _nth)
    {
        len = _len;
        nth = _nth;
    }
    bool operator < (const bridge &br) const
    {
        if (len == br.len) return nth < br.nth;
        return len < br.len;
    }
};
bool cmp2(kong a ,kong b)
{
    if (a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}
bool cmp3(kong a ,kong b)
{
    return a.nth < b.nth;
}
bool cmp4(bridge a,bridge b)
{
    return a.len < b.len;
}
vector<island> isl;
vector<kong> ko;
vector<bridge> bri;
set<bridge>::iterator it;
set<bridge> brset;
int main()
{
    long long n ,m;
    scanf("%I64d%I64d",&n,&m);
    brset.clear();
    for (int i = 1; i <= n ; i ++)
    {
        island now;
        scanf("%I64d%I64d",&now.l,&now.r);
        isl.push_back(now);
    }
    sort(isl.begin(),isl.end(),cmp1);
    for (int i = 1 ; i <= m; i ++)
    {
        bridge now;
        scanf("%I64d",&now.len);
        now.nth = i;
        bri.push_back(now);
        brset.insert(now);
    }

    sort(bri.begin(), bri.end(),cmp4);
    for (int i = 1; i < n ; i ++)
    {
        kong now ;
        now.nth = i - 1;
        now.l = isl[i].l - isl[i - 1].r;
        now.r = isl[i].r - isl[i - 1].l;
        ko.push_back(now);
    }
    sort(ko.begin(),ko.end(),cmp2);

    int j = 0;
    int i;
    for (i = 0 ; i < ko.size() ; i ++)
    {
        bridge now(ko[i].l,-1);
        it = brset.lower_bound(now);
        if (it == brset.end()) break;
        if (it->len > ko[i].r) break;
        ko[i].ans = it->nth;
        brset.erase(*it);
        //while (j != bri.size() && (bri[j].len < ko[i].l || bri[j].len > ko[i].r)) j ++;
        //if ( j == bri.size() ) break;
        //ko[i].ans = bri[j].nth;
        //j ++;
    }
    sort(ko.begin(),ko.end(),cmp3);

    if ( i != ko.size() )
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    printf("%I64d",ko[0].ans);
    for (int i = 1; i < ko.size() ; i ++)
    {
        printf(" %I64d",ko[i].ans);
    }

}
