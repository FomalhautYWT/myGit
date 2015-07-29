#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int inf=~0u >> 2;
const int maxn=40000;
const int maxm=2000000;
int pre[maxm],other[maxm],last[maxn],f[maxm];
int prex[maxm],prep[maxm],now[maxn],dis[maxn],level[maxn],tmp[maxn];
int matrix[600][600];
int n,m,l,c;
using namespace std;

void add_edge(int x,int y,int z)
{
	pre[++l]=last[x];last[x]=l;other[l]=y;f[l]=z;
	pre[++l]=last[y];last[y]=l;other[l]=x;f[l]=0;
}

int isap(int s,int t,int tot)
{
	int mina,x=s,pos,y,delta=inf;int flow=0;
	bool flag;
	for (int i=0;i<=tot;i++)now[i]=last[i];
	
	memset(level,0,sizeof(int) * (n + m + m + 10));
	memset(dis,0,sizeof(int) * (n + m + m + 10));
	level[0]=tot;
	while (dis[s]<tot)
	{
		flag=false;
		tmp[x]=delta;
		for (int p=now[x];p!=-1;p=pre[p])
		{
			y=other[p];
			if (f[p]>0 && dis[x]==dis[y]+1)
			{
				flag=true;
				prex[y]=x;prep[y]=p;now[x]=p;
				if (delta>f[p]) delta=f[p];
				x=y;
				if (x==t)
				{
					flow+=delta;
					while (x!=s)
					{
						int k=prep[x];
						f[k]-=delta;
						f[k^1]+=delta;
						x=prex[x];
					}
					delta=inf;
				}
				break;
			}
		}
		if (flag) continue;
		mina=tot-1;
		pos=-1;
		for (int p=last[x];p!=-1;p=pre[p])
		{
			if (f[p]>0 && dis[other[p]]<mina)
			{
				mina=dis[other[p]];
				pos=p;
			}
		}
		now[x]=pos;
		level[dis[x]]--;
		if (level[dis[x]]==0) break;
		dis[x]=mina+1;
		level[dis[x]]++;
		if (x!=s)
		{
			x=prex[x];
			delta=tmp[x];
		}
	}
	return flow;
}

int fastflow(int T)
{
	int s = 0, e = n + m*2 +1, tot=n+m*2+2;
	for (int i=1;i<=n;i++) add_edge(s,i,1);
	for (int i=n+1;i<=n+m;i++)
	{
		add_edge(i,e,1);
		add_edge(i+m,e,1);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (matrix[i][j] <= T)
			add_edge(i,j+n,1);
			if ((matrix[i][j]+c)<=T)
			add_edge(i,j+n+m,1);
		}
	}
	
	int ans = isap(s,e,tot);
	return ans;
}

int main()
{
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int k;
				
		scanf("%d%d%d%d",&n,&m,&k,&c);
		
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		scanf("%d",&matrix[i][j]);
		int low = -1 , high = 20000000 + 10 ;
		for( ; low + 1 < high; ) {
			l=-1;
			memset(last,-1,sizeof(int) * (n + m + m + 10));
			//memset(pre,-1,sizeof(pre));
			int mid = (low + high) / 2;
			if (fastflow(mid) >= k) high = mid;
			else low = mid;
		}
		cout << high << endl;
	}
//	system("pause");
}







