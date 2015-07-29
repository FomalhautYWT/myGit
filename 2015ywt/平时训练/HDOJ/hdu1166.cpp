#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 500000;

int n ; 
int a[maxn];
int limit;
int sum[maxn];

void build(int x,int ll,int rr)
{
	int ls = x << 1 , rs = ls + 1;
	if (ll == rr)
	{
		if (ll <= n) 
		{
			sum[x] = a[ll];
		}
		else 
		{
			sum[x] = 0 ;
		}		
		return ;
	}
	int mid = ll + rr >> 1;
	build( ls , ll , mid );
	build( rs , mid + 1 , rr );
	sum[x] = sum[ls] + sum[rs] ;
}

void modify(int x,int ll,int rr,int k,int d)
{
	int ls = x << 1 , rs = ls + 1 , mid = ll + rr >> 1;
	if (ll == rr)
	{
		sum[x] += d;
		return ;
	}
	if ( k <= mid ) modify( ls , ll , mid , k , d);
	else modify( rs , mid + 1 , rr , k , d);
	sum[x] = sum[ls] + sum[rs];
}

int ask(int x,int ll,int rr,int l ,int r)
{
	int ls = x << 1 , rs = ls + 1;
	if (ll == l && rr == r) return sum[x];
	int mid = ll + rr >> 1;
	int ans = 0 ;
	if (mid >= r) ans = ask (ls , ll ,mid , l , r);
	else if ( l > mid ) ans = ask (rs , mid + 1 , rr , l , r);
	else
	{
		ans = ask(ls , ll , mid , l , mid ) + ask(rs , mid+1,rr,mid+1,r);
	} 
	return ans ;
}

int main()
{
	int testCase;
	
	scanf("%d",&testCase);
	for (int i = 1 ; i <= testCase ; i ++ ) 
	{
		scanf("%d",&n);
		printf("Case %d:\n",i);
		int temp = 0;
		for (int j = 1 ; j <= n ; j ++)
		{
			scanf("%d",&a[j]);
		}getchar();
		limit = 1;
		while (limit <= n) limit = limit << 1;
		build(1,1,limit);
		while ( 1 )
		{
			char str[10] ;
			int p , q;
			scanf("%s",str);
			if (str[0] == 'E')
			{
				break;
			}
			scanf("%d %d",&p,&q);
			if (str[0] == 'Q')
			{
				printf("%d\n",ask(1,1,limit,p,q));
			}
			else if (str[0] == 'S')
			{
				modify(1,1,limit,p,-q);
			}
			else if (str[0] == 'A')
			{
				modify(1,1,limit,p,q);
			}
			
		}
	}
}
