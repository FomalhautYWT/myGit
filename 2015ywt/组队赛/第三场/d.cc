#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define debug 0

typedef long long ll;
struct tree{
	int lv, minlv,maxlv, f;
	ll maxexp, exp;
} p[100000];

int n, k, q;
int need[100];
char buf[10];

void pushdown(int rt){
	if (p[rt].f){
		p[rt<<1].maxexp = p[rt<<1].maxexp + (long long)p[rt].f * k;
		p[rt<<1|1].maxexp = p[rt<<1|1].maxexp + (long long)p[rt].f * k;
		p[rt<<1].f += p[rt].f;
		p[rt<<1|1].f += p[rt].f;
		p[rt].f = 0;
	}
}
void pushup(int rt){
	p[rt].minlv = min(p[rt<<1].minlv, p[rt<<1|1].minlv);
	p[rt].maxlv = max(p[rt<<1].maxlv, p[rt<<1|1].maxlv);
	p[rt].maxexp = max(p[rt<<1].maxexp, p[rt<<1|1].maxexp);
}
void build(int rt, int l, int r){
	if (l == r){
		p[rt].exp = 0, p[rt].lv = 1;
		p[rt].minlv = 1, p[rt].maxexp = 0;
		p[rt].f = 0;
		return;
	}
	int m = l + r >> 1;
	p[rt].f = p[rt].lv = 0;
	build(rt<<1, l, m);
	build(rt<<1|1, m+1, r);
	pushup(rt);
}
ll query(int L, int R, int rt, int l, int r){
	if (L <= l && r <= R){
		if (debug){
			puts("");
			printf("%d %d %d %d\n", rt, l, r, p[rt].maxexp);
			puts("");
		}
		return p[rt].maxexp;
	}
	ll ret = 0;
	int m = l + r >> 1;
	pushdown(rt);
	if (L <= m) ret = max(ret, query(L, R, rt<<1, l, m));
	if (m < R) ret = max(ret, query(L, R, rt<<1|1, m+1, r));
	if (debug){
		puts("");
		printf("%d %d %d %d\n", rt, l, r, p[rt].maxexp);
	}
	pushup(rt);
	if (debug){
		printf("%d %d %d %d\n", rt, l, r, p[rt].maxexp);
		puts("");
	}
	return ret;
}
void modify(int L, int R, int E, int rt, int l, int r){
	if (p[rt].minlv == p[rt].maxlv){

		if (L <= l && r <= R){
			p[rt].f += E;
			if (l == r) p[rt].exp = p[rt].exp + (long long)k * E;
			p[rt].maxexp = p[rt].maxexp + (long long)k * E;
			return;
		}
		int m = l + r >> 1;
		pushdown(rt);
		if (L <= m) modify(L, R, E, rt<<1, l, m);
		if (m < R) modify(L, R, E, rt<<1|1, m+1, r);
		pushup(rt);
	}
	else{
		if (L <= l && r <= R && l == r){
			p[rt].maxexp = p[rt].exp = p[rt].exp + (long long)E * p[rt].lv;
			while(p[rt].lv != k && p[rt].exp >= need[p[rt].lv]) p[rt].lv++;
			p[rt].minlv = p[rt].lv;
			return;
		}
		int m = l + r >> 1;
		pushdown(rt);
		if (L <= m) modify(L, R, E, rt<<1, l, m);
		if (m < R) modify(L, R, E, rt<<1|1, m+1, r);
		pushup(rt);
	}
}
int T, cas;
int main()
{
	scanf("%d", &T);
	cas = 0;
	while(T--){
		printf("Case %d:\n", ++cas);
		scanf("%d %d %d", &n, &k, &q);
		for (int i = 1; i < k; i++){
			scanf("%d", &need[i]);
		}
		build(1, 0, n-1);
		while(q--){
			scanf("%s", buf);
			int L, R, E;
			if (buf[0] == 'Q'){
				scanf("%d %d", &L, &R);
				printf("%I64d\n", query(L-1, R-1, 1, 0, n-1));
			}
			else{
				scanf("%d %d %d", &L, &R, &E);
				modify(L-1, R-1, E, 1, 0, n-1);
			}
		}
	}
	return 0;
}
