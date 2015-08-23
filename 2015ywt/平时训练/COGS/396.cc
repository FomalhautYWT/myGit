#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define DEBUG 0
const int MAX_V = 5000;
const int MAX_M = 500000;
const int INF = 99999999;
int is[10002];
int S , T , cntN , n , m , ans = 0;

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
bool yes;
void prepare()
{
    yes = false;
    totEdge = edges;
    memset(E,NULL,sizeof(E));
    S = 0;
    T = n + n + 1;
    cntN = T + 1;
}

void make_graph()
{
    for (int i = 1; i <= 100 ; i ++)
        is[i * i] = true;
    for (int i = 1; i <= n ; i ++)
        for (int j = 1 ; j < i ; j ++)
        {
            if (is[i + j])
                addEdge(j , i + n , 1);
        }
    for (int i = 1; i <= n ; i ++)
    {
        addEdge(S,i,1);
        addEdge(i+n,T,1);
    }
}

int Xans;
void print()
{
    ans = n - maxflow();
    if (ans > Xans)
    {
        yes = true;
    }
}

int main()
{
    freopen("balla.in","r",stdin);
    freopen("balla.out","w",stdout);
    scanf("%d",&Xans);
    yes = false;
    int l = 1 , r = 1600;

    while (r != l)
    {
        int mid = l + r >> 1 ;
        n = mid;
        prepare();
        make_graph();
        print();
        if (yes) r = mid;
        else l = mid + 1;
    }

    printf("%d\n",l - 1);

    fclose(stdin);
    fclose(stdout);
}
