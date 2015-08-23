#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200007

struct Q{
    int a, b, len;
}q[N];

int n, s[2][N*2];
int r[N*2];

int lb(int k) {return k&-k;}

int sum(int k, int p) {
    int re = 0;
    while (k) {
        re += s[p][k];
        k -= lb(k);
    }
    return re;
}

void add(int k, int p, int v) {
    while (k <= n) {
        s[p][k]+=v;
        k += lb(k);
    }
}

int find(int a) {
    int l = 0, rr = n-1, mid;
    while (l < rr) {
        mid = l+rr>>1;
        if (r[mid] < a) l = mid+1;
        else rr = mid;
    }
    return l+1;
}
int main() {
    int T, m, ca = 1, i;
    while (~scanf("%d", &m)) {
        n = 0;
        int len = 1;
        for (i = 1;i <= m;i++) {
            scanf("%d%d", &q[i].a, &q[i].b);
            if (!q[i].a) {
                r[n++] = q[i].b, r[n++] = q[i].b+len;
                q[i].len = len++;
            }
        }
        sort(r, r+n);
        n = unique(r, r+n)-r;
       // for (i = 0;i < n;i++) printf("%d ", r[i]);puts("");
        memset(s, 0, sizeof(s));
        printf("Case #%d:\n", ca++);
        for (i = 1;i <= m;i++) {
            if (q[i].a) {
                int tm = q[i].b;
                int b = q[q[i].b].b;
                add(find(b), 0,-1), add(find(b+q[tm].len), 1, -1);
            }else {
                //printf("[%d %d]\n", find(q[i].b+1), find(q[i].b));
                int L = find(q[i].b), R = find(q[i].b+q[i].len);
                printf("%d\n", sum(R, 1)-sum(L-1, 0));
                add(R, 1, 1), add(L, 0, 1);
            }
        }
    }
}
