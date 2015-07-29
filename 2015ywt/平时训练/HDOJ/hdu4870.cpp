#include <cstdio>
#include <cstring>
#include <cmath>

const double eps=1e-7;

double dp[20];
double p;

int main() {
	int i,j;
	double ans;
	while (scanf("%lf",&p)!=EOF) {
		dp[0]=1/p;
		dp[1]=(1+(1-p)*dp[0])/p;
		for (i=2;i<20;i++) {
			dp[i]=(1+(1-p)*(dp[i-2]+dp[i-1]))/p;
		}
		ans=dp[19];
		for (i=0;i<19;i++) {
			ans+=dp[i]+dp[i];
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}
