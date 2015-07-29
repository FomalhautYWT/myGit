#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
pair<double,int> a[15005];
int n;
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
    {
        scanf("%lf%d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1);
    int sum = 0;
    for (int i = 1; i <= n ; i ++)
    {
        sum += a[i].second;
    }
    sum = sum / 2 + (sum & 1);
  //  cout << "sum " << sum << endl;
    int p = 0;
    double ans = 0;
    for (int i = 1; i <= n ; i ++)
    {
        if ( p + a[i].second >= sum && p + a[i].second >=sum)
        {
            ans = a[i].first;
            break;
        }
        p += a[i].second;
//        cout << "p " << p << endl;
    }

    printf("%.5lf\n",ans);
}
