#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
set<int> s;
int main()
{
    s.clear();
    int n;
    scanf("%d",&n);
    int ans = 0;
    char str[10];
    for (int i = 1; i <= n ; i ++)
    {
        int p;
        scanf("%s %d",str,&p);
        if (str[0] == '+')
        {
            s.insert(p);
            if (s.size() > ans)
                ans = s.size();
        }
        else{
            if (s.find(p) == s.end())
                ans ++;
            else s.erase(p);
        }
    }
    cout << ans << endl;
}
