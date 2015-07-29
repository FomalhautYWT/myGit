#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int limit = 1;
int n , m ;
int sum [400000];
int flag[400000];

void build(int x,int ll, int rr)
{
	int ls = x << 1 , rs = ls + 1, mid = ll + rr >> 1;
	flag[x] = 0;
	if (ll == rr)
	{

		if (ll > n) sum[x] = 0; else
		sum[x] = 1;
		return ;
	}
	build ( ls , ll , mid ) ; 
	build ( rs , mid+1 , rr ); 
	sum[x] = sum[ls] + sum[rs];
}

void modify(int x,int ll ,int rr ,int l , int r , int d)
{
	int ls = x << 1 , rs = ls + 1 , mid = ll + rr >> 1 ; 
	if ( ll == l && rr == r )
	{
		flag[x] = d ;
		sum[x] = d * (rr - ll + 1);
		return ;
	}
	if ( flag[x] )
	{
		flag[ls] = flag[x];
		flag[rs] = flag[x];
		sum[ls] = flag[x] * (mid - ll + 1);
		sum[rs] = flag[x] * (rr - mid);
		flag[x] = 0;
	}
	if ( r <= mid ) modify( ls , ll , mid , l , r , d );
	else if ( l > mid ) modify( rs , mid + 1 , rr , l , r , d);
	else 
	{
		modify(ls , ll , mid , l , mid , d );
		modify(rs , mid+1, rr, mid+1, r , d);
	}
	sum[x] = sum[ls] + sum[rs];
}

int ask(int x,int ll,int rr,int l ,int r)
{
	int ls = x << 1 , rs = ls + 1 , mid = ll + rr >> 1;
	if ( ll == l && rr == r)
	{
		return sum[x];
	}
	if (flag[x])
	{
		flag[ls] = flag[x];
		flag[rs] = flag[x];
		sum[ls] = flag[x] * (mid - ll + 1);
		sum[rs] = flag[x] * (rr - mid);
		flag[x] = 0;
	}
	if ( r <= mid ) return ask(ls,ll,mid,l,r);
	else if (l > mid ) return ask(rs, mid+1 , rr , l ,r);
	else return ask(ls, ll , mid ,l ,mid)+ask(rs,mid+1,rr,mid+1,r);
}


int main()
{
	int caseTest;
	scanf("%d",&caseTest);
	for (int i = 1 ; i <= caseTest ; i ++)
	{
	//	memset(flag,0,sizeof(flag));
		scanf("%d%d",&n,&m);
		limit = 1;
		while ( limit < n ) limit = limit << 1;
		build(1 , 1 , limit);
		//cout <<"!"<<endl;
		for(int j = 1 ; j <= m ; j ++)
		{
			int p , q , r ;
			scanf("%d%d%d",&p,&q,&r);
			modify( 1, 1, limit, p, q, r);
			//printf("Case %d: The total value of the hook is %d.\n",i,ask(1,1,limit,1,n));
		}
		printf("Case %d: The total value of the hook is %d.\n",i,ask(1,1,limit,1,n));
	}
}
