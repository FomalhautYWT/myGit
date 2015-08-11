#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAX_V = 500;
const int MAX_M = 5000;
const int INF = 99999999;
int S , T , cntN , n , m , ans = 0;

bool getint(int &x)
{
    int ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    x = ch - '0' ;
    while (isdigit(ch = getchar())) x = x * 10 - '0' + ch ;
    if (ch == '\n' || ch == '\r') return true;
    return false;
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
void prepare()
{
    totEdge = edges;
    memset(E,NULL,sizeof(E));
    S = 0 ;
    T = n + m + 1;
    cntN = T + 1;
}

void make_graph()
{
    for (int i = 1; i <= m ; i ++)
    {
        int x;
        scanf("%d",&x);
        ans += x;
        addEdge(0,i,x);
        while(true)
        {
            int y;
            bool end = getint(y);
            addEdge(i,y + m,INF);
            if (end) break;
        }
    }
    for (int i = m + 1; i <= m + n ; i ++)
    {
        int x;
        scanf("%d",&x);
        addEdge(i,T,x);
    }
}
int que[10000],que1[10000];
int r = 0,r1 = 0;
int v[10000];
void dfs(int x)
{
    for (Edge *p = E[x]; p!=NULL; p = p->n)
    {
        if (p->c && !v[p->t])
        {
            v[p->t] = true;
            dfs(p->t);
        }
    }
}
void print()
{
    ans = ans - maxflow();
    v[S] = 1;
    dfs(S);
    bool flag = true;
    for (int i = 1 ; i <= m ; i ++)
        if (v[i])
        {
            if (flag)
            {
                printf("%d",i);
                flag = false;
                continue;
            }
            printf(" %d",i);
        }
    puts("");
    flag = true;
    for (int i = m + 1 ; i <= T ; i ++)
    {
        if (v[i])
        {
            if (flag)
            {
                printf("%d",i-m);
                flag = false;
                continue;
            }
            printf(" %d",i - m);
        }
    }
    puts("");
    printf("%d\n",ans);
}

int main()
{
    freopen("shuttle.in","r",stdin);
    freopen("shuttle.out","w",stdout);
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        prepare();
        make_graph();
        print();
    }
    fclose(stdin);
    fclose(stdout);
}
