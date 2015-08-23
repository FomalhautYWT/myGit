#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int a[200000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n ; i++)
        scanf("%d",&a[i]);
    sort(a + 1 , a + n + 1);
    a[0] = a[n];
    a[n + 1] = a[1];
    for (int i = 1; i <= n ; i ++)
    {
        cout << min(abs(a[i] - a[i-1]),abs(a[i+1] - a[i])) << " " << max(a[i] - a[1],a[n] - a[i]) << endl;
    }
}
