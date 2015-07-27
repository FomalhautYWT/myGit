#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
int primeNum[200000];
int pr[200000];
int pNum = 0;
vector<pair<int ,int> > vc;
void split(int p)
{
    vc.clear();
    for (int i = 0 ; i < pNum && (p > 1) ; i ++)
    {
        while (p % primeNum[i] == 0)
        {
            if (vc.empty())
            {
                vc.push_back(make_pair(primeNum[i],1));
                p /= primeNum[i];

                continue;
            }
            if ( vc[vc.size() - 1].first == primeNum[i] )
                vc[vc.size() - 1].second ++;
            else
                vc.push_back(make_pair(primeNum[i],1));
            p /= primeNum[i];
        }
    }
    if (p != 1)
    {
        vc.push_back(make_pair(p , 1));
    }
}
void prime()
{
    for (int i = 2 ; i <= 100000; i ++)
    {
        if (!pr[i]) primeNum[pNum ++] = i;
        for (int j = 0 ; (j < pNum) && (primeNum[j] * i < 100000) ; j ++)
        {
            pr[primeNum[j] * i] = 1;
            if ( i % primeNum[j] == 0 ) break;
        }
    }
}

int calc(int a ,int b)
{
    if (a == b) return 1;
    int l = a - b;
    return (l + 1)*(l + 1)*(l + 1) - 2 * l * l * l + (l - 1)*(l - 1)*(l - 1);
}
vector<pair <int , int > > gcv , lcv;
int main()
{
    int cas;
    prime();
    scanf("%d",&cas);

    while (cas --)
    {
        gcv.clear();
        lcv.clear();
        long long ans = 1;
        int gc , lc;
        scanf("%d%d",&gc,&lc);
        split(gc);
        gcv = vc;
        split(lc);
        lcv = vc;
        int j = 0;
        for (int i = 0 ; i < lcv.size() ; i ++)
        {

            if (j == gcv.size())
            {
                int num1 = lcv[i].second;
                int num2 = 0;
                ans *= calc(num1 , num2);
                continue;
            }
            if (gcv[j].first == lcv[i].first)
            {
                int num1 = lcv[i].second;
                int num2 = gcv[j].second;
                ans *= calc(num1 , num2);
                j ++;
            } else
            {
                int num1 = lcv[i].second;
                int num2 = 0;
                ans *= calc(num1 , num2);
            }
        }
        if (j != gcv.size())
            ans = 0;
        printf("%I64d\n",ans);
    }
}
