#include<iostream>
#include<cstdio>
using namespace std;

int k ;
int main()
{
	int k, n;
	while(~scanf("%d",&n)){
		int k = 1;
		while (k*(k-1)/2<n) k++;
		printf("%d\n",k);
		if (k*(k-1)/2==n){
			for (int i=k;i>=1;i--){
				if (i!=k) printf(" ");
				printf("%d",i);
			}
			printf("\n");
		} else {
			int top = 1 + n - (k-1)*(k-2)/2;
			printf("%d",top);
			for (int i=k;i>=1;i--)
				if (i!=top) printf(" %d",i);
			printf("\n");
		}
	}
}
