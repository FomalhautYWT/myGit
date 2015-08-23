#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX_V = 50000;
const int MAX_M = 500000;
const int INF = 99999999;
int S , T , cntN , ans = 0;

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

int a[50000];
int f[50000];
int n;
int dpans;
void dp()
{
    for (int i = n ; i >= 1 ; i --){


        for (int j = i + 1 ; j <= n ; j ++)
        {
            if (a[i] <= a[j]) f[i] = max(f[i],f[j] + 1);
            if (dpans < f[i]) dpans = f[i];
        }

    }


}
void prepare()
{
    dpans = 0;
    ans = 0;
    for (int i = 1; i <= n ; i ++) f[i] = 1;
    totEdge = edges;
    memset(E,NULL,sizeof(E));
    S = 0;
    T = 2 * n + 1;
    cntN = T + 1;
}

void make_graph()
{
    for(int i = 1 ; i <= n ; i ++)
    {
        addEdge(i,i+n,1);
        if (f[i] == dpans) addEdge(S,i,INF);
        if (f[i] == 1 ) addEdge(i + n , T , INF);
    }
    for (int i = 1; i <= n ; i ++)
        for (int j = i ; j <= n ; j ++)
        if (j > i && a[j] >= a[i] && f[j]+1 == f[i]) addEdge(i+n,j,1);
}

void print()
{
    printf("%d\n",dpans);
    int last = maxflow();
    printf("%d\n",last);
    addEdge(1,1+n,INF);
    addEdge(n,n+n,INF);
    //addEdge(S,1,INF);
    //addEdge(n+n,T,INF);
    ans = maxflow()+last;
    if (ans > n) ans = n;
    printf("%d\n",ans);
}

int main()
{
    freopen("alis.in","r",stdin);
    freopen("alis.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1 ; i <= n ; i ++)
        scanf("%d",&a[i]);
    prepare();
    dp();
    make_graph();
    print();
    fclose(stdin);
    fclose(stdout);
}
