#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if ( n < 9 ) cout << 0 << endl;
	else if ( n == 9 ) cout << 8 << endl;
	else 
	{
		n -= 10;
		cout << 72 ;
		for (int i = 1; i <= n ; i ++)
		cout << 0 ;
		cout << endl;
	}
}	
