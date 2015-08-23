#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1003

struct M{
    int h, d;
    bool operator<(M a)const {
        if (h == a.h) return d > a.d;
        return h < a.h;
    }
}ap[N];

int dp1[N], dp2[N];
int top1, top2;

int find(int d, int v, int top) {
    if (d == 1 && dp1[1] <= v) {
        return 1;
    }
    if (d == 2 && dp2[1] <= v) {
        return 1;
    }
    int l = 1, r = top, mid;
    while (l < r) {
        mid = l+r>>1;
        if (d == 1) {
            if (dp1[mid] <= v) r = mid;
            else l = mid+1;
        }else {
            if (dp2[mid] <= v) r = mid;
            else l = mid+1;
        }
    }
    return l;
}

int main() {
    int T, n, i, j;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1;i <= n;i++) {
            scanf("%d%d", &ap[i].h, &ap[i].d);
        }
        sort(ap+1, ap+n+1);
        top1 = top2 = 0;
        for (i = 1;i <= n;i++) {
            if (top1 == 0) {
                dp1[++top1] = ap[i].d;
            }else if (top2 == 0) {
                dp2[++top2] = ap[i].d;
            }else {
                if (dp1[top1] >= ap[i].d && dp2[top2] >= ap[i].d) {
                    if (dp1[top1] > dp2[top2]) {
                        dp2[++top2] = ap[i].d;
                    }else {
                        dp1[++top1] = ap[i].d;
                    }
                }else if (dp1[top1] >= ap[i].d) {
                    dp1[++top1] = ap[i].d;
                }else if (dp2[top2] >= ap[i].d) {
                    dp2[++top2] = ap[i].d;
                }else {
                    int t1 = find(1, ap[i].d, top1);
                    int t2 = find(2, ap[i].d, top2);
                    if (dp2[t2] > dp1[t1]) {
                        dp1[t1] = ap[i].d;
                    }else dp2[t2] = ap[i].d;
                }
            }
        }
        printf("%d\n", top1+top2);
    }
}
