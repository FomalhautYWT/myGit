/*

	Jirachi
	将每张牌视作无向边 ， 对整张图求欧拉路即可
	注意图不连通的情况
	2014 - 07 - 10

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int map[100][100];
int cnt ;
int edge[200][2] , du[10];
int ans[200][2], s ;
int vis[200];
int n ;

void dfs( int u )
{
	for ( int i = 0 ; i <= 6 ; i ++) 
	{
		if ( map[u][i] )
		{
			map[u][i]-- ; 
			map[i][u]-- ; 
			dfs ( i ) ; 
			cnt ++ ; 
			ans[cnt][0] = u ; 
			ans[cnt][1] = i ;
		}
	}
}

int add_edge(int x,int y,int z)
{
	du[x]++; 
	du[y]++;
	map[x][y]++;
	map[y][x]++;
	edge[z][0] = x; 
	edge[z][1] = y;
}
int prepare()
{
	scanf("%d",&n);
	memset(du, 0 ,sizeof(du));
	memset(map , 0 , sizeof(map));
	memset(vis , 0 , sizeof(vis));
	for (int i = 1; i <= n ; i++)
	{
		int p , q ;
		scanf("%d%d",&p,&q);
		add_edge(p,q,i);
	}
}
int solve()
{
	for ( int i = 0 ; i <= 6 ; i ++ )
	{
		if ( du[i] ) s = i ;
	}
	cnt = 0 ;
	for ( int i = 0 ; i <= 6 ; i ++ )
	{
		if ( du[i] & 1 )
		{
			cnt ++;
			s = i ;
		}
	}
	if ( cnt > 2 )
	{
		cout << "No solution\n" << endl;
		return 0;
	}
	cnt = 0 ; 
//	cout << s<< endl;
	dfs ( s );
	//cout << cnt << endl;
	if ( cnt < n ) 
	{
		cout << "No solution\n" << endl;
		return 0;
	}
	for ( int i = cnt ; i >= 1; i -- )
	{
		for ( int j = 1 ; j <= n ; j++ ) 
		{
			if ( !vis[j] && edge[j][0] == ans[i][0] && edge[j][1] == ans[i][1] )
			{
				printf("%d +\n", j );
				vis[j] = 1 ; 
				break;
			}
			else if ( ! vis[j] && edge[j][0] == ans[i][1] && edge[j][1] == ans[i][0] )
			{
				printf("%d -\n", j );
				vis[j] = 1 ; 
				break;
			}
		}	
	}
}
int main()
{
	prepare();
	solve();
	
}
