#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
bool check(int a ,int b ,int c ,int d)
{
    if (a + b + c > d && a + b < c + d) return true;
    return false;
}
int n;
int a[99999];
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d",&a[i]);
    sort(a + 1, a + n + 1);
    for (int i = n - 3; i >= 1 ; i --)
        if (check(a[i] , a[i + 1] , a[i + 2] , a[i + 3]))
        {

            //cout << i <<endl;
            //cout << a[i] <<" " << a[i + 1] <<" "<< a[i + 2] <<" "  << a[i + 3] << endl;
            printf("%d\n",a[i]+a[i+1]+a[i + 2]+a[i + 3]);
            return 0;
        }
    cout << -1 <<endl;

}
