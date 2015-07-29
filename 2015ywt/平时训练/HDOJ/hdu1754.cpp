#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int limit = 1;

int maxn[500000] , a[500000];
int n , m ;

void build(int x,int ll,int rr)
{
	int ls = x << 1 , rs = ls + 1 , mid = ll + rr >> 1;
	if (ll == rr)
	{
		if (ll <= n) maxn[x] = a[ll];
		else maxn[x] = 0;
		return ;
	}
	build( ls , ll , mid );
	build( rs , mid + 1 , rr );
	maxn[x] = max( maxn[ls] , maxn[rs] );
}

void modify(int x,int ll,int rr,int k,int d)
{
	int ls = x << 1 , rs = ls + 1 , mid = ll + rr >> 1 ;
	if (ll == rr)
	{
		maxn[x] = d;
		return ;
	}
	if ( k <= mid ) modify( ls , ll , mid , k , d );
	else modify( rs , mid+1 , rr , k , d );
	maxn[x] = max( maxn[ls] , maxn[rs] );
}

int ask(int x,int ll,int rr,int l,int r)
{
	int ls = x << 1 , rs = ls + 1 , mid = ll + rr >> 1;
	if (ll == l && rr == r) return maxn[x];
	int ans = 0;
	if (mid >= r) ans = ask (ls , ll , mid , l , r);
	else if (l > mid) ans = ask (rs , mid+1 , rr , l , r);
	else 
	{
		ans = max(ask(ls,ll,mid,l,mid),ask(rs,mid+1,rr,mid+1,r));
	}
	return ans;
}

int main()
{
	while ( scanf("%d%d",&n,&m)!=EOF )
	{
		for (int i = 1 ; i <= n ; i ++)
		{
			scanf("%d",&a[i]);
		}
		limit = 1;
		while (limit < n) limit = limit << 1;
		build( 1 , 1 , limit );
		for (int i = 1 ; i <= m ; i ++)
		{
			char str[5];
			int p, q;
			scanf("%s%d%d",str,&p,&q);
			if (str[0] == 'Q') 
			{
				printf("%d\n",ask(1,1,limit,p,q));
			}
			else if (str[0] == 'U')
			{
				modify(1,1,limit,p,q);
			}
		}
	}
}
