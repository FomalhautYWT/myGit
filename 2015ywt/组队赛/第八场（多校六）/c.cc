#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<vector>
using namespace std;
long long n , m;
long long sum (long long n)
{
    return n * (n + 1) / 2;
}
set<long long> s;
vector <long long> anan[20];
set<long long>::iterator it;
int main()
{
    int cas;
    scanf("%d",&cas);

    while(cas --)
    {
        scanf("%I64d%I64d",&n,&m);
        long long nowans = sum(n);
        s.clear();
        for (int i = 0 ; i <= 20 ; i ++)
            anan[i].clear();
        if (nowans % m == 0 && nowans / m >= n)
        {
            bool flag = true;
            long long ans = nowans / m;
            for (int i = 1; i <= n ; i ++)
                s.insert(-i);
            int nowi = 0;
            while (!s.empty())
            {
                long long now = -ans;
                while (now)
                {
                    it = s.lower_bound(now);
                    if (it == s.end())
                    {
                        flag = false;
                        break;
                    }
                    now -= *it;
                    anan[nowi].push_back(*it);
                    s.erase(*it);
                }
                nowi ++;
                if (flag == false)
                    break;
            }
            if (flag == false)
            {
                puts("NO");
            }
            else{
                for(int i = 0 ; i < nowi ; i ++)
                {
                    printf("%d",anan[i].size());
                    for (int j = 0 ; j < anan[i].size() ; j ++)
                        printf(" %d",-anan[i][j]);
                    puts("");
                }
            }
        }
        else
        {
            puts("NO");
            continue;
        }
    }
}
