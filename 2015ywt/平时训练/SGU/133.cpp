#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
vector<pair<int ,int> > s;
bool cmp(pair<int,int> a , pair<int,int> b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i =1 ; i <= n ; i ++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        s.push_back(make_pair(a,b));
    }
    sort(s.begin(),s.end(),cmp);
    int ans = 0;
    int now = 0;
    for (int i = 0 ; i < s.size() ; i ++)
    {
        //cout << s[i].first << " " << s[i].second<<" " << now <<endl;
        if (now <= s[i].second)
            now = s[i].second;
        else
        {
            ans++;//
           // cout <<ans<<endl;
        }

    }
    printf("%d\n",ans);
}
