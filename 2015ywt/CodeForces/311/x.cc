#include <bits/stdc++.h>
using namespace std;

vector < vector<int > > g;
int sz[2];
long long cnt;
bool vis[100005], color[100005], f;

void dfs(int u, bool c)
{
	vis[u] = 1;
	color[u] = c;
	cnt += sz[color[u]];
	sz[color[u]]++;
	for (int i = 0; i < g[u].size(); i++)
	{
		if (!vis[g[u][i]])
			dfs(g[u][i], c ^ 1);
		else if (color[g[u][i]] == c)
		{
			printf("0 1\n");
			exit(0);
		}
	}
}

int main()
{
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	g.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	if (m == 0)
	{
		printf("3 %lld\n", (1LL * n * 1LL * (n - 1) * 1LL * (n - 2)) / 6);
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (!vis[i])
			sz[0]=sz[1]=0,dfs(i, 0);
	if (!cnt)
		printf("2 %lld\n", m * 1LL * (n - 2));
	else
		printf("1 %lld\n", cnt);
	return 0;
}
