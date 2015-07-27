#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
vector< pair<int , int > > vc , vc2;
int n ;
int main()
{
    while (scanf("%d",&n), n)
    {
        vc.clear();
        vc2.clear();
        int ans = 0;
        for (int i = 1; i <= n; i ++)
        {
            int x, y ;
            scanf("%d%d",&x,&y);
            vc.push_back(make_pair(x,y));
            vc2.push_back(make_pair(y,x));
        }
        sort(vc.begin(),vc.end());
        sort(vc2.begin(),vc2.end());
        for (int i = 1 ; i < vc.size() ; i ++)
        {
            if (i & 1)
            ans += vc[i].second - vc[i - 1].second;
        }
        for (int i = 1 ; i < vc2.size() ; i ++)
        {
            if (i & 1)
            ans += vc2[i].second - vc2[i - 1].second;
        }
        printf("The length of the fence will be %d units.\n",ans);

    }
}
