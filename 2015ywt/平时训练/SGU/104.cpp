#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std ;

const int N = 105;

int n , m ;
int val[N][N];
int f[N][N];
int anst[N];
int from[N][N];
int ans = 0, ansx = 0 ,ansy = 0;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 0 ; i <= n+1; i ++)
	for (int j = 0 ; j <= m+1; j ++)
	{
		f[i][j] = -99999999;
	}
	ans = -999999999;
	f[0][0] = 0;
	for (int i = 1; i <= n ; i ++)
	{
		for (int j = 1; j <= m ; j ++)
		{
			scanf("%d",&val[i][j]);
		}
	}
	for (int i = 1; i<=n; i ++)
	{
		for (int j = 1; j <= m ; j ++)
		{
			for (int k = i-1; k < j ;k++)
			{
				if (f[i][j]<val[i][j]+f[i-1][k])
				{
					from[i][j] = k;
					f[i][j] = val[i][j] + f[i-1][k];
				}
			}
		}
	}
	
	int ansi = 1;
	for (int i = 2; i <= m ; i ++)
	if (f[n][i]>f[n][ansi]) ansi = i;
	printf("%d\n",f[n][ansi]);
	for (int i = n ; i>=1 ;ansi = from[i][ansi] , i --)
	{
		anst[i] = ansi;
	}
	
	for (int i = 1; i <= n ; i ++)
	printf("%d ",anst[i]);
//	printf("%d\n",anst[1]);
}
