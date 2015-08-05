#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef long double ld;

const int maxn = 100000 + 10;

ii a[2 * maxn];
ld ans, pw[maxn];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[i] = ii(x, y);
		a[i + n] = ii(x, y);
	}
	pw[0] = 1.0;
	for(int i = 1; i <= 100; i++) pw[i] = pw[i - 1] * 2.0;
	ans = 1.0;
	if(n <= 100) {
		for(int i = 0; i < n; i++) {
			for(int j = 1; j <= min(n - 2, 100); j++) {
				ld prob = (pw[n - j - 1] - 1) / (pw[n] - 1 - n - (ld) n * (n - 1) / 2);
				ld area = (ld) 0.5 * (1LL * a[i].first * a[i + j].second - 1LL * a[i + j].first * a[i].second);
				ans += prob * (area - 0.5 * __gcd(abs(a[i].first - a[i + j].first), abs(a[i].second - a[i + j].second)));
			}
		}
	} else {
		for(int i = 0; i < n; i++) {
			ld prob = 0.5;
			for(int j = 1; j <= min(n - 2, 100); j++) {
				prob *= 0.5;
				ld area = (ld) 0.5 * (1LL * a[i].first * a[i + j].second - 1LL * a[i + j].first * a[i].second);
				ans += prob * (area - 0.5 * __gcd(abs(a[i].first - a[i + j].first), abs(a[i].second - a[i + j].second)));
			}
		}
	}
	printf("%.10lf\n", (double) ans);
	return 0;
}
