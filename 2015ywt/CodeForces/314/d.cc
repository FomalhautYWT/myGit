#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
using namespace std;

map<int , int> ma;
map<int,int>::iterator l , r , it;
int x[300000];
int main()
{
    ma.clear();
    int n, k , a , m;
    scanf("%d%d%d",&n,&k,&a);
    scanf("%d",&m);
    for (int i = 1 ; i <= m ; i ++)
        scanf("%d",&x[i]);
    int tmp = (n + 1) / (a + 1);
    ma[0] = tmp ;
    ma[n + 1] = 0;
    for (int i = 1 ; i <= m ; i ++)
    {
        it = ma.lower_bound(x[i]);
        r = it;
        l = --it;
        tmp -= l->second;
        int nowl , nowr;
        nowl = (x[i] - l->first) / (a + 1);
        nowr = (r->first - x[i]) / (a + 1);
        ma[l->first] = nowl;
        ma[x[i]] = nowr;
        tmp += nowl + nowr;
        if (tmp < k)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}

