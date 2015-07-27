#include<iostream>
#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX_V = 200000;
const int INF = ~0u >> 2;
const int MAX_M = 500000;
int gx[604][604];
set<int> ss;
int S , T , n;
int cntN;
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
    cntN = 2 * n ;
    memset(E,NULL,sizeof(E));
    totEdge = edges;
}
bool check(int p)
{
    return (ss.find(p) != ss.end());
}
int ans[9999];
int len = 0;
int theMaxFlow;
int main()
{
    scanf("%d%d%d",&n,&S,&T);
    for (int i = 1; i <= n ; i ++)
        for (int j = 1; j <= n ; j ++)
        {
            scanf("%d",&gx[i][j]);
        }
    if (gx[S][T] || gx[T][S])
    {
        printf("NO ANSWER!\n");
        return 0;
    }
    ss.clear();
    for (int i = 0; i <= n ; i ++)
    {
        if ( i == S || i == T ) continue;
        prepare();
        for (int j = 1; j <= n ; j ++)
        {
            if (!check(j) && j!= i)
                addEdge(j , j + n , 1);
        }
        addEdge(S,S+n,~0u >> 2);
        for (int j = 1 ; j <= n ; j ++)
        {
            if (!check(j) && j != i)
            for (int k = 1 ; k <= n ; k ++)
            {
                if (!check(k) && k != i)
                if (gx[j][k])
                    addEdge(j+n , k , 1);
            }
        }
        int nowMaxflow = maxflow();
        //cout << nowMaxflow << endl;
        if ( i == 0 ) {
            theMaxFlow = nowMaxflow;
            continue;
        }
        if (nowMaxflow == theMaxFlow - 1)
        {
            theMaxFlow = nowMaxflow;
            ans[++len] = i;
            ss.insert(i);
        }
    }
    printf("%d\n",len);

    for (int i = 1 ; i <= len ; i ++)
        printf("%d ",ans[i]);
    printf("\n");
}
