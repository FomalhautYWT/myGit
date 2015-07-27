#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400,M=5000;
const double inf=1e10,eps=1e-6;
int head[N],nc,du[N];
struct data
{
	int x,y;
}po[M];
struct edge
{
	int x,y,next;
	double cap;
} edge[M*3];
void add(int x,int y,double cap)
{
	edge[nc].x=x;
	edge[nc].y=y;
	edge[nc].cap=cap;
	edge[nc].next=head[x];
	head[x]=nc++;
	edge[nc].x=y;
	edge[nc].y=x;
	edge[nc].cap=0;
	edge[nc].next=head[y];
	head[y]=nc++;
}
int num[N],h[N],S,T,n,m;
double findpath(int x,double flow)
{
	if(x==T) return flow;
	double res=flow;
	int pos=n-1;
	for(int i=head[x]; i!=-1; i=edge[i].next)
	{
		int y=edge[i].y;
		if(h[x]==h[y]+1&&edge[i].cap>eps)
		{
			double tp=findpath(y,min(edge[i].cap,res));
			res-=tp; edge[i].cap-=tp;
			edge[i^1].cap+=tp;
			if(res<eps||h[S]==n)
				return flow-res;
		}
		if(edge[i].cap>eps&&h[y]<pos)
			pos=h[y];
	}
	if(abs(res-flow)<eps)
	{
		num[h[x]]--;
		if(num[h[x]]==0)
		{
			h[S]=n;
			return flow-res;
		}
		h[x]=pos+1;
		num[h[x]]++;
	}
	return flow-res;
}
double Sap(double x)
{
	memset(head,-1,sizeof(head));
	nc=0;
	for(int i=0;i<m;i++)
	{
		add(po[i].x,po[i].y,1.0);
		add(po[i].y,po[i].x,1.0);
	}
	for(int i=1;i<T;i++)
	{
		add(S,i,(double)m);
		add(i,T,(double)m+2*x-(double)du[i]);
	}
	double ans=0;
	memset(h,0,sizeof(h));
	memset(num,0,sizeof(num));
	while(h[S]!=n)
		ans+=findpath(S,(T-1)*m);
	return (T-1.0)*m-ans;
}
bool vis[N];
int dfs(int now)
{
	int cnt=1;
	vis[now]=true;
	for(int i=head[now];i!=-1;i=edge[i].next)
	{
		if(!vis[edge[i].y]&&edge[i].cap>eps)
		{
			cnt+=dfs(edge[i].y);
		}
	}
	return cnt;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(du,0,sizeof(du));
		S=0;T=n+1;n=T+1;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&po[i].x,&po[i].y);
			du[po[i].x]++;du[po[i].y]++;
		}
		if(m==0)
		{
			printf("1\n1\n");
			continue;
		}
		double ll=0,rr=(double)m,mid;
		while(rr-ll>1.0/(T-1.0)/(T-1.0))
		{
			mid=(ll+rr)/2.0;
			double tp=Sap(mid);
			if(abs(tp)<eps)
				rr=mid;
			else
				ll=mid;
		}
		memset(vis,false,sizeof(vis));
		int ans=dfs(S)-1;
		if(ans==0)
		{
			Sap(ll);
			memset(vis,false,sizeof(vis));
			ans=dfs(S)-1;
		}
		printf("%d\n",ans);
		for(int i=1;i<T;i++)
		if(vis[i])
			printf("%d\n",i);
	}
	return 0;
}
