#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define DEBUG 0
const int MAX_V = 500;
const int MAX_M = 50000;
const int INF = 99999999;
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

void prepare()
{
    scanf("%d%d",&n,&m);
    totEdge = edges;
    memset(E,NULL,sizeof(E));
    S = 0;
    T = n + n + 1;
    cntN = T + 1;
}

void make_graph()
{
    for (int i = 1; i <= m ; i ++)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        addEdge(x , y + n , 1);
    }
    for (int i = 1; i <= n ; i ++)
    {
        addEdge(S,i,1);
        addEdge(i+n,T,1);
    }
}

void print()
{

    ans = n - maxflow();
    if (DEBUG)
    {
        for (Edge *p = E[4];p != NULL ; p = p-> n)
            cout << p->t - n << endl;
    }
    for (int i = 1; i <= n ; i ++)
    {
        int now = i;
        if (E[now + n]->c != 0)
        {
            printf("%d",now);
            bool flag = true;
            while(flag)
            {
                flag = false;
                for (Edge *p = E[now]; p != NULL ; p = p->n)
                {
                    if (p->c == 0)
                    {
                        if (p->t == 0) break;
                        printf(" %d",p->t - n);
                        now = p->t - n;
                        flag = true;
                        break;
                    }
                }
            }
            printf("\n");
        }
    }
    printf("%d\n",ans);

}

int main()
{
    freopen("path3.in","r",stdin);
    freopen("path3.out","w",stdout);
    prepare();
    make_graph();
    print();
    fclose(stdin);
    fclose(stdout);
}
