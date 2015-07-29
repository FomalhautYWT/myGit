#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int cnt ;
int v [ 1 << 18 ] ;
int ans [ 1 << 18 ] ;
int n ;

int dfs( int p )
{
	int t = 1 << n ;
	t -- ;
	t = t & ( p << 1 ) ;
	if ( !v[ t ] ) 
	{
		v[ t ] = 1 ;
		dfs( t );
		ans[ ++ cnt ] = 0 ;
	}
	if ( !v[ ++ t ] )
	{
		v[ t ] = 1 ;
		dfs( t );
		ans[ ++ cnt ] = 1 ;
	}
}

int main()
{
	while ( scanf( "%d" , &n ) != EOF )
	{
		printf( "%d " , 1 << n );
		cnt = 0;
		memset( v , 0 , sizeof ( v ) ) ;
		dfs( 0 );
		for ( int i = 1 ; i < n ; i ++ ) printf( "0" );
		for ( int i = cnt ; i > n ; i -- )
		printf( "%d" , ans[ i ] ) ;
		printf( "%d\n" , ans[ n ] ) ;
	}
	return 0;
}
