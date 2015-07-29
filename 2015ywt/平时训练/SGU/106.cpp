#include<iostream>
#include<cstdio>
using namespace std;
long long a , b , c ;
long long x1 , x2 , y1 , y2 ;
long long cnt ;
long long exgcd(long long a , long long b , long long &x , long long &y)
{
	if ( !b )
	{
		x = 1 ;
		y = 0 ;
		return a;
	}
	long long d = exgcd( b , a % b , x , y );
	long long temp = x;
	x = y ;
	y = temp - ( a / b ) * y ;
	return d ;
}
int main()
{	
	scanf("%lld%lld%lld%lld%lld%lld%lld", &a , &b , &c , &x1 , &x2 , &y1 , &y2);
	c *= -1;
	if ( a==0 && b==0 )
	{
		if ( !c ) 
		{
			cnt = ( x2 - x1 + 1 ) * ( y2 - y1 + 1 );
		}
	}
	else if ( !a )
	{
		if ( c % b == 0 && c / b >= y1 && c / b <= y2 )
		{
			cnt = x2 - x1 + 1 ;
		}
	}
	else if ( !b )
	{
		if ( c % a == 0 && c / a >= x1 && c / a <= x2 )
		{
			cnt = y2 - y1 + 1;
		}
	}
	else 
	{
		long long x = 0 , y = 0;
		long long d = exgcd( a , b , x , y );
		if ( c % d == 0 )
		{
			long long tx = x * (c / d) ;
			long long ty = y * (c / d);
			long long lx , ly ,rx , ry;
			if ( x1 <= tx || (x1 - tx) * d % b == 0 ) 
			{
				lx = (x1 - tx) * d / b ;
			}
			else
			{
				lx = (x1 - tx) * d / b + 1;
			}
			if ( x2 >= tx || (tx - x2) * d % b == 0 )
			{
				rx = (x2 - tx) * d / b ;
			}
			else
			{
				rx = (x2 - tx) * d / b - 1;
			}
			if ( y1 <= ty || (y1 - ty) * d % a == 0 )
			{
				ly = (ty - y1) * d / a;
			}
			else
			{
				ly = (ty - y1) * d / a - 1;			
			}
			if ( y2 >= ty || (ty - y2) * d % a == 0 )
			{
				ry = (ty - y2) * d / a ;
			}
			else 
			{
				ry = (ty - y2) * d / a + 1;			
			}
			if ( lx > rx ) swap( lx , rx );
			if ( ly > ry ) swap( ly , ry );
			if ( lx <= ry && ly <= rx )
			{
				long long maxans = max(lx , ly);
				long long minans = min(rx , ry);
				cnt = minans - maxans + 1;
			}
		}
	}
	cout << cnt << endl;
}
