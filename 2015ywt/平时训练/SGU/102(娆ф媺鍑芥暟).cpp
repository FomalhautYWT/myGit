/*

	Jirachi 
	裸求 n 的欧拉函数
	模板题
	2014 - 07 - 10

*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;


int euler_phi(int n)
{
	int m = floor(sqrt(n+0.5));
	int ans = n;
	for(int i = 2; i <= m; i++) if(n%i == 0)
	{
		ans = ans / i * (i-1);
		while(n%i == 0)
		{
			n /= i;
		}
	}
	if(n > 1) ans = ans / n *(n-1);
	return ans;
}



int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n", euler_phi(n));
    return 0;
}
