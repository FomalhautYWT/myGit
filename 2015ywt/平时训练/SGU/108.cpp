#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int ans[1000000];
bool v[100];
int n , k , num = 0;

int check(int p)
{
	int t = p ;
	while (t)
	{
		p += t % 10;
		t /= 10;
	}
	return p;
}

int main()
{
	memset(v,0,sizeof(v));
	scanf("%d%d",&n,&k);
	//cout << check(2) << endl;
	for (int i = 1; i <= n ; i ++)
	{
		if (!v[i%100]) ans[++num] = i;
		v[i%100]=0;
		v[check(i)%100] = 1;
	}
	cout << num << endl;
	for (int i = 1; i < k ; i ++)
	{
		int std;
		scanf("%d",&std);
		cout << ans[std] << " " ;
	}
	int std;
	scanf("%d",&std);
	cout << ans[std] << endl;
}
