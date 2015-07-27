#include <bits/stdc++.h>
using namespace std;
typedef pair <long long, long long> PLL;
vector <PLL> forbid;

int main() {
	int h, q, x, y;
	long long l, r;

	scanf("%d%d", &h, &q);

	while(q--) {
		scanf("%d%I64d%I64d%d", &x, &l, &r, &y);
		l = l << (h - x); r = (r << (h - x)) + (1LL << (h - x)) - 1;
		if(y == 0) {
			forbid.push_back(make_pair(l, r));
		} else {
			forbid.push_back(make_pair(1LL << (h - 1), l - 1));
			forbid.push_back(make_pair(r + 1, (1LL << h) - 1));
		}
	}
	forbid.push_back(make_pair((1LL << (h - 1)) - 1, (1LL << (h - 1)) - 1));
	forbid.push_back(make_pair((1LL << h), (1LL << h)));

	sort(forbid.begin(), forbid.end());

	int cnt = 0;
	long long ans = -1;
	long long far = 0;

	for(int i = 0; i < forbid.size() - 1; i++) {
		far = max(far, forbid[i].second);
		long long u = max(forbid[i].second, far) + 1;
		long long v = forbid[i + 1].first - 1;
		if(v > far && u <= v) {
			cnt++;
			if(u == v) ans = u;
		}
	}
	if(cnt == 0) {
		printf("Game cheated!\n");
	} else if(cnt == 1 && ans != -1) {
		printf("%I64d\n", ans);
	} else {
		printf("Data not sufficient!\n");
	}
	return 0;
}
