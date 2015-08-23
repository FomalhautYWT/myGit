#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#define N 200005

struct E{
    int a, b;
    int v, ne;
    E(){}
    E(int _v, int _ne, int _a, int _b):v(_v), ne(_ne), a(_a), b(_b){}
}e[N];

int size = 0, head[N];

void init() {
    size = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int a, int b) {
    e[size] = E(v, head[u], a, b);
    head[u] = size++;
}

double dis[N];
bool vis[N];

void dfs(int u) {
    int i, v;
    int a, b;
    for (i = head[u];i!=-1;i = e[i].ne) {
        v = e[i].v, a = e[i].a, b = e[i].b;
        if (vis[v]) continue;
        dis[v] = dis[u]*a/b;
        vis[v] = true;
        dfs(v);
    }
}

map<string,int>M;
map<int,string>MM;

int main() {
    int n, i, j, ca = 1;
    char op1[20], op2[20];
    while (~scanf("%d", &n)) {
        init();
        memset(vis, false, sizeof(vis));
        M.clear(), MM.clear();
        int u, v, a, b, cnt = 0;
        for (i = 0;i < n;i++) {
            scanf("%d %s = %d %s", &a, op1, &b, &op2);
            if (M.find(string(op1)) == M.end()) {
                M[op1] = cnt++;
            }
            if (M.find(string(op2)) == M.end()) {
                M[op2] = cnt++;
            }
            u = M[op1], v = M[op2];
            MM[u] = op1, MM[v] = op2;
            add(u, v, a, b);
            add(v, u, b, a);
        }

        scanf("%d%s", &a, op1);
        u = M[op1];
        dis[u] = 1.0;
        vis[u] = true;
        dfs(u);
        int ans = -1, id;
        double tm;
        for (i = 0;i < cnt;i++) {
            if (!vis[i]) continue;
            int tt = a*dis[i]+0.5;
            double di = tt*dis[i]-a;
            if (ans == -1) {
                tm = di; ans = tt, id = i;
            }else if (di < tm) {
                tm = di, ans = tt, id = i;
            }
        }
        printf("Case %d: %d %s\n", ca++, ans, id);
    }
}
