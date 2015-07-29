 #include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int limit ;
int sum1[700002] , sum2[700002] , sum3[700002];
int flagAdd[700002] , flagModi[700002] , flagMult[700002] ;
const int MOD = 10007;

int update(int x, int lch , int rch)
{
	sum1[x] = sum1[lch] + sum1[rch] ;
	sum2[x] = sum2[lch] + sum2[rch] ;
	sum3[x] = sum3[lch] + sum3[rch] ;
}


void renew( int type, int x, int ll, int rr, int c )
{
	if ( type == 0 )
	{
		sum3[x] = ( sum3[x] + 3 * c * sum2[x] % MOD + 3 * c * c % MOD * sum1[x] % MOD+ c * c % MOD * c % MOD * (rr - ll + 1) % MOD ) % MOD;
		sum2[x] = ( sum2[x] + 2 * c * sum1[x] % MOD + c * c % MOD * ( rr - ll + 1 ) % MOD ) % MOD;
		sum1[x] = ( sum1[x] + c * ( rr - ll + 1 ) % MOD ) % MOD; 
		flagAdd[x] = (flagAdd[x] + c) % MOD;
	}
	else if ( type == 1 )
	{
		sum3[x] = ( sum3[x] * c % MOD * c % MOD * c % MOD );
		sum2[x] = ( sum2[x] * c % MOD * c % MOD );
		sum1[x] = ( sum1[x] * c % MOD );
		flagAdd[x] = flagAdd[x] * c % MOD ;
		flagMult[x] = flagMult[x] * c % MOD ;
	}
	else if ( type == 2 )
	{
		sum3[x] = c * c % MOD * c % MOD * ( rr - ll + 1 ) % MOD;
		sum2[x] = c * c % MOD * ( rr - ll + 1 ) % MOD;
		sum1[x] = c * ( rr - ll + 1 ) % MOD;
		flagModi[x] = c;
		flagMult[x] = 1;
		flagAdd[x] = 0;
	}
}

void pushDown( int x, int ll, int rr )
{
	int mid = ll + rr >> 1;
	if ( flagModi[x] )
	{
		renew(2 , x << 1 , ll , mid , flagModi[x]);
		renew(2 , x<<1|1 , mid+1 ,rr, flagModi[x]);
		flagModi[x] = 0;
	}
	if ( flagMult[x] )
	{
		renew(1 , x << 1 , ll , mid , flagMult[x]);
		renew(1 , x<<1|1 , mid+1,rr , flagMult[x]);
		flagMult[x] = 1;
	}
	if ( flagAdd [x] )
	{
		renew(0 , x << 1 , ll , mid , flagAdd[x]);
		renew(0 , x<<1|1 , mid+1,rr , flagAdd[x]);
		flagAdd[x] = 0;
	}
}

void build(int x, int ll, int rr)
{
	int ls = x << 1 , rs = ls | 1 , mid = ll + rr >> 1;
	if ( ll == rr )
	{
		sum1[x] = 0;
		sum2[x] = 0;
		sum3[x] = 0;
		flagAdd[x] = 0;
		flagMult[x] = 1;
		flagModi[x] = 0;
		return ;
	}
	build ( ls , ll , mid );
	build ( rs , mid+1 , rr );
	update( x , ls , rs );
}

void add(int x, int ll, int rr, int l, int r, int d ,int type)
{
	int ls = x << 1 , rs = ls | 1 , mid = ll + rr >> 1;
	if ( l == ll && r == rr)
	{
		renew(type , x , ll , rr , d);
		return ;
	}
	pushDown(x , ll , rr);
	if ( r <= mid ) add( ls , ll , mid , l , r , d , type );
	else if ( l > mid ) add( rs , mid + 1 , rr , l , r , d , type );
	else {
		add ( ls , ll , mid , l , mid , d , type );
		add ( rs , mid+1 ,rr ,mid+1,r , d , type );
	}
	update(x , ls , rs);
}

int ask ( int x, int ll, int rr, int l, int r, int type)
{
	int ls = x << 1 , rs = ls | 1 , mid = ll + rr >> 1;
	if ( l == ll && r == rr )
	{
		if ( type == 1 ) return sum1[x] ;
		else if ( type == 2 ) return sum2[x];
		else return sum3[x];
	}
	pushDown(x , ll , rr);
	if ( r <= mid ) return ask( ls , ll , mid , l , r , type );
	else if ( l > mid ) return ask ( rs , mid + 1 , rr , l , r ,type );
	else
	{
		return (ask ( ls ,ll , mid , l , mid ,type ) + ask ( rs , mid+1 , rr , mid+ 1 , r , type )) % MOD;
	}
	update(x , ls , rs);
	
}

int main()
{
	int n, m ;
	while (scanf("%d%d", &n, &m) ,n + m)
	{
		limit = 1; 
		while ( n > limit ) limit = limit << 1;
		//build( 1, 1, limit );
		memset(sum1 , 0 ,sizeof ( sum1 ));
		memset(sum2 , 0 ,sizeof ( sum2 ));
		memset(sum3 , 0 ,sizeof ( sum3 ));
		memset(flagAdd,0,sizeof(flagAdd));
		memset(flagModi,0,sizeof(flagModi));
		for (int i = 1; i <= limit << 1 ; i ++) flagMult[i] = 1;
		for (int i = 1; i <= m ; i ++)
		{
			int qu , x , y , c ;
			scanf("%d%d%d%d", &qu, &x, &y, &c);
			if ( qu < 4 )
			{
				add(1 , 1 , limit , x , y , c , qu - 1 );
			}
			else if ( qu == 4 )
			{
				printf("%d\n",ask(1 , 1 , limit , x , y , c));
			}
		}
		
	}
}
