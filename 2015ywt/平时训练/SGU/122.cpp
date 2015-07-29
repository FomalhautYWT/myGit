#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1050;
int n,st,en,l;
bool bel[maxn]={0};
int co[maxn]={0};
bool e[maxn][maxn]={0};
int pr[maxn],ne[maxn];
bool add(int x,bool su)
{
	int i,j;
	for(i=1;i<=n;i++)
		if(e[x][i]&&!bel[i]) 
		{
			for(j=1;j<=n;j++) 
				if(e[i][j]) co[j]=i;
			if(!su) ne[i]=x,pr[x]=i,st=i;
			else ne[x]=i,pr[i]=x,en=i;
			bel[i]=1;
			l++;
			return 1;
		}
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in","r",stdin);
#endif
	int i,j,t;
	char ci;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(i==1) en=t;
		e[i][t]=1;
		ci=getchar();
		while(ci!='\n'&&ci!='\r'&&ci!=EOF)
			scanf("%d",&t),e[i][t]=1,ci=getchar();
	}
	st=1,l=2;
	bel[st]=bel[en]=1;
	ne[st]=en,pr[en]=st;
	while(1)
	{
		while(add(st,0));
		while(add(en,1));
		if(e[st][en])
		{
			if(l==n) {ne[en]=st,pr[st]=en;break;}
			for(i=1;i<=n;i++)
				if(!bel[i]&&co[i])
				{
					ne[en]=st,pr[st]=en;
					st=i,en=pr[co[i]];
					ne[st]=co[i],pr[co[i]]=st;
					bel[i]=1,l++;
					break;
				}
		}
		else 
			for(i=ne[st];ne[i]!=en;i=ne[i])
			{
				if(e[i][en]&&e[st][ne[i]]) 
				{
					for(j=en;j!=i;j=ne[j])
						swap(pr[j],ne[j]);
					t=ne[i];
					ne[i]=en,pr[en]=i;
					en=t;
					break;
				}
			}
	}
	for(i=1;i!=pr[1];i=ne[i])
		printf("%d ",i);
	printf("%d %d\n",pr[1],1);
	return 0;
}
