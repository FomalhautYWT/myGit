#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n ;
	cout << (n / 3)*2 + (n % 3 == 2) <<endl;
}
