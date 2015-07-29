#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn = 501;
const int maxm = 15000;
const int inf = 99999999;

int s , t;
int n , m;
int C[maxn] , riC[maxn] , tiB[maxn] , tiP[maxn] ;
int pre[maxm] , other[maxm] , last[maxn] , len[maxm];
int visit[maxn];
int l = 0;

int dist[maxn] , lastx[maxn] , que[maxm*10] , ans[maxn];

int add_edge(int x,int y, int z)
{
	pre[++l] = last[x] ; last[x] = l ; other[l] = y ; len[l] = z ;
	pre[++l] = last[y] ; last[y] = l ; other[l] = x ; len[l] = z ;
}

int prepare()
{
	scanf("%d%d", &s , &t);getchar();
	scanf("%d%d", &n , &m);getchar();
	for (int i = 1 ; i <= n ; i ++)
	{
		char color;
		scanf("%c%d%d%d",&color,&riC[i],&tiB[i],&tiP[i]);
		getchar();
		if (color == 'B') C[i] = 0;
		else C[i] = 1;
	}
	//cout <<"!"<<endl;
	for (int i = 1 ; i <= m ; i ++)
	{
		int p , q, r ;
		scanf("%d%d%d",&p,&q,&r);
		add_edge(p,q,r);
	}
}

void color ( int nowx , int nowtime , int &ca ,int &ta )
{
	if ( nowtime < riC[nowx] ) 
	{
		ta = riC[nowx] ; 
		ca = C[nowx];
		return ;
	}
	else 
	{
		int temp = ( nowtime - riC[nowx] ) % ( tiB[nowx] + tiP[nowx] );
		int now = nowtime - temp ;
		if ( C[nowx] == 1 ) 
		{
			if ( temp < tiB[nowx]) 
			{
				ca = 0 ; 
				ta = now + tiB[nowx];
				return ;
			}
			else 
			{
				ca = 1 ; 
				ta = now + tiB[nowx] + tiP[nowx] ;
				return ;
			}
		}
		else
		{
			if ( temp < tiP[nowx] )
			{
				ca = 1 ;
				ta = now + tiP[nowx];
				return ;
			}
			else 
			{
				ca = 0 ;
				ta = now + tiB[nowx] + tiP[nowx] ; 
				return ;
			}
		}
	}
	
}


int deal(int nowx ,int nowp , int nowtime ,int f)
{
	int ca , cb , ta , tb ;
	int nowy = other[nowp];
	color ( nowx , nowtime , ca , ta );
	color ( nowy , nowtime , cb , tb );
	if (ca == cb ) return nowtime ; 
	if (ta == tb )
	{
		if ( f == 0 ) 
		return deal(nowx , nowp , ta , 1) ;
		else if (nowtime <= riC[nowx] || nowtime <= riC[nowy]) 
		return deal(nowx , nowp , ta , 1);
		else return inf ;
	}
	return min(ta , tb);
}

void spfa()
{
	int l = 0 , r = 1;
	memset( visit , 0 , sizeof( visit ));
	for ( int i = 0 ; i <= t ; i ++ ) dist[i] = inf ;
	que[1] = s ; visit[s] = 1; dist[s] = 0;lastx[s] = 0;

	while ( l != r )
	{
		int x = que[++l];
		for (int p = last[x] ; p != 0; p = pre[p])
		{
			int now = deal( x, p , dist[x] ,0);
			if ( now >= inf ) break;
			if ( len[p] + now < dist[other[p]] ) 
			{
				dist[other[p]] = len[p] + now;
				lastx[other[p]] = x ;
				if ( !visit[other[p]] )
				{
					visit[other[p]] = 1 ;
					que[++r] = other[p] ;
				}
			}
		}
		visit[x] = 0 ;
	}
	if ( dist[t] >= inf ) 
	{
		cout << "0" << endl;
		return ;
	}
	cout << dist[t] <<endl;
	int fw = t , leng = 0 ;
	while ( fw ) 
	{
		ans[++leng] = fw ; 
		fw = lastx[fw];
	}
	for (int i = leng ; i > 1 ; i --)
	{
		printf("%d ", ans[i]);
	}
	printf("%d\n",ans[1]);
	return ;
}

int main()
{
	prepare();
	spfa();
	
	
}
