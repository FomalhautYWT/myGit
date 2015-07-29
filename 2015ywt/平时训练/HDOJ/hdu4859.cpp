#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int caseTest;


#include <cstdio>
#include <cstring>

using namespace std;

const long long MAXINT=(1ll<<60);
const int N=5010;
const int M=30010;

struct NetWorkFlow {
	struct Edge {
		int t;
		long long f;
		Edge *ne,*p;
		Edge () {}
		Edge (int tt,int ff,Edge *nee) {
			t=tt;f=ff;ne=nee;
		}
		void *operator new(size_t,void *p) {
			return p;
		}
	};
	Edge b[M*2];
	Edge *p,*fe[N],*cur[N];
	int n,s,t;
	int h[N],vh[N];
	void clear(int nn,int ss,int tt) {
		n=nn;s=ss;t=tt;
		for (int i=0;i<=n;i++) fe[i]=NULL;
		p=b;
	}
	void putedge(int x,int y,int f) {
		fe[x]=new(p++)Edge(y,f,fe[x]);
		fe[y]=new(p++)Edge(x,0,fe[y]);
		fe[x]->p=fe[y];
		fe[y]->p=fe[x];
	}
	long long aug(int i,long long f) {
		if (i==t) return f;
		long long l=f;
		for (Edge *&j=cur[i];j;j=j->ne) {
			if (j->f&&h[j->t]+1==h[i]) {
				long long tmp=aug(j->t,l<j->f?l:j->f);
				j->f-=tmp;
				j->p->f+=tmp;
				l-=tmp;
				if (h[s]==n||!l) return f-l;

			}
		}
		int minh=n-1;
		for (Edge *j=cur[i]=fe[i];j;j=j->ne) {
			if (j->f&&h[j->t]<minh) minh=h[j->t];
		}
		minh++;
		if (!--vh[h[i]]) h[s]=n;
		else ++vh[h[i]=minh];
		return f-l;
	}
	long long flow() {
		long long ans=0;
		vh[0]=n;
		for (int i=0;i<=n;i++) {
			cur[i]=fe[i];
			h[i]=vh[i]=0;
		}
		while (h[s]<n) ans+=aug(s,MAXINT);
		return ans;
	}
};

NetWorkFlow c;
int n,m;
char str[100][100];
int color[100][100];
int calc(int i , int j)
{
	return ( i * ( m + 1 ) + j );
}
int main() {
	scanf("%d",&caseTest);
	for (int cas = 1; cas <= caseTest ; cas++)
	{
		int i,x,y,z;
		scanf("%d%d",&n,&m);getchar();		
		int sta = (n+2)*(m+2)+1;
		int edt = sta+1;
		c.clear(edt,sta,edt);//点个数 s t

		for (int i = 1; i <= n ; i ++)
		{
			for (int j = 1; j <= m ; j ++)
			{
				scanf("%c",&str[i][j]);
			}getchar();
		}
		for (int i = 0; i <= n+1 ; i ++)
		{
			str[i][0] = str[i][m+1]='D';
		}//处理边上一圈
		
		for (int i = 0; i <= m+1 ; i ++)
		{
			str[0][i] = str[m+1][i]='D';
		}//处理边上一圈
		n++;m++;
		for (int i = 0 ; i <= n ; i ++)
		{
			for (int j = 0 ; j <= m ; j++)
			{
				color[i][j] = ((i + j) & 1);
			}
		}//黑白染色
		for (int i = 1; i < n ; i ++)
		for (int j = 1; j < m ; j ++)
		{
			c.putedge(calc(i,j),calc(i,j+1),1);
			c.putedge(calc(i,j),calc(i,j-1),1);
			c.putedge(calc(i,j),calc(i-1,j),1);
			c.putedge(calc(i,j),calc(i+1,j),1);
		}//相邻建边
		for (int i = 1 ; i < n ; i++)
		{
			c.putedge(calc(i,0),calc(i,1),1);
			c.putedge(calc(i,0),calc(i-1,0),1);
			c.putedge(calc(i,0),calc(i+1,0),1);
			c.putedge(calc(i,m),calc(i,m-1),1);
			c.putedge(calc(i,m),calc(i-1,m),1);
			c.putedge(calc(i,m),calc(i+1,m),1);
		}//处理左右边界
		for (int j = 0 ; j < m ; j++)
		{
			c.putedge(calc(0,j),calc(1,j),1);
			c.putedge(calc(0,j),calc(0,j-1),1);
			c.putedge(calc(0,j),calc(0,j+1),1);
			c.putedge(calc(n,j),calc(n-1,j),1);
			c.putedge(calc(n,j),calc(n,j-1),1);
			c.putedge(calc(n,j),calc(n,j+1),1);
		}//处理上下边界
		c.putedge(calc(0,0),calc(0,1),1);
		c.putedge(calc(0,0),calc(1,0),1);
		c.putedge(calc(n,0),calc(n,1),1);		
		c.putedge(calc(n,0),calc(n-1,0),1);
		c.putedge(calc(n,m),calc(n-1,m),1);
		c.putedge(calc(n,m),calc(n,m-1),1);
		c.putedge(calc(0,m),calc(0,m-1),1);
		c.putedge(calc(0,m),calc(1,m),1);
		//处理四个角的点
		for (int i = 0 ; i <= n ; i ++)
		{
			for (int j = 0 ; j <= m ; j++)
			{
				if (str[i][j]=='D') color[i][j] = 1 ^ color[i][j];
			}
		}
		//颜色翻转
		for (int i = 0 ; i <= n ; i++)
		{
			for (int j = 0 ; j <= m ; j ++)
			{
				if (color[i][j]) c.putedge(sta,calc(i,j),100);
				else c.putedge(calc(i,j),edt,100);
			}
		}//建立源汇边
		printf("Case %d: %lld\n",cas,c.flow());
	}
	return 0;
}
