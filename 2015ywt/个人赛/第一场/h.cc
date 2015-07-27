#include<cstring>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 100020;
int Left[20][maxn], sorted[maxn], tree[20][maxn];

void build_tree( int L, int R, int v )
{
	int i; int mid = ( L + R ) /2;
	if( L == R ) return;
	int m = sorted[mid];
	int same = mid - L + 1;
	for( i = L; i <= R; i++ )
	if( tree[v][i] < m ) same--;
	int lpos = L;
	int rpos = mid+1;
	int ss = 0;
	for( i = L; i <= R; i++ )
	{
		if( i == L ) Left[v][i] = 0;
		else Left[v][i] = Left[v][i-1];
		if( tree[v][i] < m )
		{
			tree[v+1][lpos++] = tree[v][i];
			Left[v][i]++;
		}
		else if( tree[v][i] > m )
		{
			tree[v+1][rpos++] = tree[v][i];
		}
		else { if( ss < same )
		{
			tree[v+1][lpos++] = tree[v][i];
			Left[v][i]++; ss++;
		}
		else tree[v+1][rpos++] = tree[v][i];
		}
	}
	build_tree( L, mid, v + 1 );
	build_tree( mid + 1, R, v + 1 );
}
int query( int L, int R, int l, int r, int k, int v )
{
	int mid = ( L + R ) /2 ;
	if( l == r ) return tree[v][l];
	int off;
	int cnt;
	if( l == L )
	{
		off = 0;
		cnt = Left[v][r];
	}
	else
	{
		off = Left[v][l-1];
		cnt = Left[v][r] - Left[v][l-1];
	}
	if( cnt >= k )
	{
		int lnew = L + off;
		int rnew = lnew + cnt - 1;
		return query( L, mid, lnew, rnew, k, v + 1 );
	}
	else
	{
		off = l - L - off;
		k = k - cnt;
		cnt = r - l + 1 - cnt;
		int lnew = mid + 1 + off;
		int rnew = lnew + cnt - 1;
		return query( mid + 1, R, lnew, rnew, k, v + 1 );
	}
}
int main()
{
	int n, m, l, r, k,i;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for( i = 1; i <= n; i++ )
		{
			scanf("%d",&tree[0][i]);
			sorted[i] = tree[0][i];
		}
		sort( sorted + 1, sorted + n + 1 );
		build_tree( 1, n, 0 );
		for( i = 0; i < m; i++ )
		{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",query( 1, n, l, r, k, 0 ) );
		}
	}
	return 0;
}
