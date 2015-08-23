#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1010;
const int INFS = 0x3FFFFFFF;

struct edge {
    int from, to, cap, flow;
    edge(int _from, int _to, int _cap, int _flow)
        : from(_from), to(_to), cap(_cap), flow(_flow) {}
};

class Dinic {
public:
    void initdata(int n, int s, int t) {
        this->n = n, this->s = s, this->t = t;
        edges.clear();
        for (int i = 0; i < n; i++)
            G[i].clear();
    }
    void addedge(int u, int v, int cap) {
        edges.push_back(edge(u, v, cap, 0));
        edges.push_back(edge(v, u, 0, 0));
        G[u].push_back(edges.size() - 2);
        G[v].push_back(edges.size() - 1);
    }
    bool BFS() {
        for (int i = 0; i < n; i++)
            vis[i] = false, d[i] = 0;
        queue<int> Q;
        Q.push(s);
        vis[s] = true;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                edge& e = edges[G[x][i]];
                if (e.cap > e.flow && !vis[e.to]) {
                    vis[e.to] = true;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x, int aug) {
        if (x == t || aug == 0) return aug;
        int flow = 0;
        for (int i = 0; i < G[x].size(); i++) {
            edge& e = edges[G[x][i]];
            if (d[e.to] == d[x] + 1) {
                int f = DFS(e.to, min(aug, e.cap - e.flow));
                if (f <= 0) continue;
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                aug -= f;
                if (aug == 0) break;
            }
        }
        return flow;
    }
    int maxflow() {
        int flow = 0;
        while (BFS()) {
            flow += DFS(s, INFS);
        }
        return flow;
    }
    void change(int offset) {
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i].from == s && edges[i].to == 1)
                edges[i].cap = INFS;
            if (edges[i].from == 1 && edges[i].to == offset + 1)
                edges[i].cap = INFS;
            if (edges[i].from == offset && edges[i].to == offset + offset)
                edges[i].cap = INFS;
            if (edges[i].from == offset + offset && edges[i].to == t)
                edges[i].cap = INFS;
        }
    }
private:
    vector<edge> edges;
    vector<int> G[MAXN];
    int n, s, t, d[MAXN];
    bool vis[MAXN];
};

Dinic dc;
int dp[510], seq[510];

int main() {
    freopen("alis.in","r",stdin);
    freopen("alis.out","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &seq[i]);
    memset(dp, 0, sizeof(dp));
    dp[n] = 1;
    int maxlen = 1;
    for (int i = n-1; i >= 1; i--) {
        dp[i] = 1;
        for (int j = i+1; j <= n; j++)
            if (seq[i] < seq[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxlen = max(maxlen, dp[i]);
    }
    int s = 0, t = 2*n + 1;
    dc.initdata(t + 1, s, t);
    for (int i = 1; i <= n; i++) {
        dc.addedge(i, i + n, 1);
        if (dp[i] == maxlen)
            dc.addedge(s, i, 1);
        if (dp[i] == 1)
            dc.addedge(i + n, t, 1);
        for (int j = i+1; j <= n; j++)
            if (dp[i] == dp[j] + 1 && seq[i] < seq[j])
                dc.addedge(i + n, j, 1);
    }
    int flow = dc.maxflow();
    dc.change(n);
    printf("%d\n%d\n%d\n", maxlen, flow, flow + dc.maxflow());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
