#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdlib>
using namespace std;
const int INF = ~0u >> 2;
const int MAX_N = 4000;
const int MAX_V = 4000;
const int MAX_M = 200000;
int pre[MAX_M];
int other[MAX_M];
int last[MAX_N];
int l = 0;
int len[MAX_M];
int x[MAX_M] , y[MAX_M] , t[MAX_M];
int used[MAX_N] ;
pair<int ,int > dis[MAX_N];
int S , T , n , m;
int cntN;
void add_edge(int x, int y , int p)
{
    pre[++l] = last[x] ; last[x] = l; other[l] = y ; len[l] = p;
    pre[++l] = last[y] ; last[y] = l; other[l] = x ; len[l] = p;
}
void dijkstra(int s)
{
    memset(used,0,sizeof(used));
    for (int i = 0 ; i <= n ; i ++)
    {
        dis[i].first = INF;
        dis[i].second = INF;
    }
    dis[s] = make_pair(0 , 0);
    priority_queue< pair < pair<int ,int > , int > > que;
    que.push(make_pair(make_pair(-dis[s].first,-dis[s].second),s));
    while (!que.empty())
    {
        int u = que.top().second;
        que.pop();
        if (used[u]) continue;
        used[u] = true;
        for (int p = last[u] ; p != 0 ; p = pre[p])
        {
            pair<int ,int > now = make_pair(dis[u].first + len[p] , dis[u].second + 1);
            if (now < dis[other[p]])
            {
                dis[other[p]] = now;
                que.push(make_pair(make_pair(-dis[other[p]].first,-dis[other[p]].second),other[p]));
            }
        }
    }
}

struct Edge
{
	int t, c;
	Edge *n, *r;
} *E[MAX_V], edges[MAX_M], *totEdge;

Edge* makeEdge(int s, int t, int c)
{
	Edge *e = totEdge ++;
	e->t = t; e->c = c; e->n = E[s];
	return E[s] = e;
}

void addEdge(int s, int t, int c)
{

	Edge *p = makeEdge(s, t, c), *q = makeEdge(t, s, 0);
	p->r = q; q->r = p;
}

int maxflow()
{
	static int	cnt		[MAX_V];
	static int	h		[MAX_V];
	static int	que		[MAX_V];
	static int	aug		[MAX_V];
	static Edge	*cur	[MAX_V];
	static Edge	*prev	[MAX_V];
	fill(h, h + cntN + 1 , cntN);
	memset(cnt, 0, sizeof cnt);
	int qt = 0, qh = 0; h[T] = 0;
	for(que[qt ++] = T; qh < qt; ) {
		int u = que[qh ++];
		++ cnt[h[u]];
		for(Edge *e = E[u]; e; e = e->n)
			if (e->r->c && h[e->t] == cntN) {
				h[e->t] = h[u] + 1;
				que[qt ++] = e->t;
			}
	}
	memcpy(cur, E, sizeof E);
	aug[S] = INF; Edge *e;
	int flow = 0, u = S;
	while (h[S] < cntN) {
		for(e = cur[u]; e; e = e->n)
			if (e->c && h[e->t] + 1 == h[u])
				break;
		if (e) {
			int v = e->t;
			cur[u] = prev[v] = e;
			aug[v] = min(aug[u], e->c);
			if ((u = v) == T) {
				int by = aug[T];
				while (u != S) {
					Edge *p = prev[u];
					p->c -= by;
					p->r->c += by;
					u = p->r->t;
				}
				flow += by;
			}
		} else {
			if (!-- cnt[h[u]]) return flow;
			h[u] = cntN;
			for(e = E[u]; e; e = e->n)
				if (e->c && h[u] > h[e->t] + 1)
					h[u] = h[e->t] + 1, cur[u] = e;
			++ cnt[h[u]];
			if (u != S) u = prev[u]->r->t;
		}
	}
	return flow;
}
void make_graph()
{
    cntN = n + 1;
    S = 1;
    T = n;
    memset(E , NULL , sizeof(E));
    totEdge = edges;
    for (int i = 1; i <= m ; i ++)
    {
        if (dis[x[i]].first + t[i] == dis[y[i]].first)
        {
            addEdge(x[i],y[i],1);
        }
        if (dis[y[i]].first + t[i] == dis[x[i]].first)
        {
            addEdge(y[i],x[i],1);
        }
    }
}
void prepare()
{
    memset(last,0,sizeof(last));
    memset(pre,0,sizeof(pre));
    memset(other,0,sizeof(other));
}
int main()
{
    //freopen("1007.in","r",stdin);
    while(scanf("%d%d",&n,&m) != EOF){
        l = 0;
        prepare();
        for (int i = 1; i <= m ; i ++)
        {
            scanf("%d%d%d",&x[i],&y[i],&t[i]);
            add_edge(x[i] , y[i] , t[i]);
        }
        dijkstra(1);
        int ans1 = (m - dis[n].second);
        make_graph();
        int ans2 = maxflow();
        printf("%d %d\n",ans2 , ans1);
    }
    //fclose(stdin);
}
