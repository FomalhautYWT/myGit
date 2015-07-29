#include<iostream>
#include<cstdio>
using namespace std;
long long n , k , ans;
int c[100002];
int main()
{
	cin >> n >> k ;
	int t = k / 2 + (k & 1);
	bool flag = 0;
	for (int i = 1; i <= n ; i ++)
	{
		int x;
		scanf("%d",&x);
		x++;
		if ( x % k == 0 ) flag = 1;
		x -= t + t;
		ans ++;
		ans += x / k ;
	}
	if ((k & 1) && (flag)) ans ++;
	cout << ans << endl;
}
