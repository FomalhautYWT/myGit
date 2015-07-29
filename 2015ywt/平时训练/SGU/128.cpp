#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define Maxn 20100
#define lx (x<<1)
#define rx ((x<<1) | 1)
#define MID ((l + r)>>1)

struct Point
{
	int x,y;
}p[Maxn];

vector <int> s[Maxn<<2],match[Maxn];
int maxx,ans,vis[Maxn],S[Maxn<<2];

bool cmpy(int a,int b) {return p[a].y<p[b].y;}
bool cmpx(int a,int b) {return p[a].x<p[b].x;}

void init()
{
	maxx = 0;
	ans = 0	;
	memset(vis,0,sizeof(vis));
	memset(S,0,sizeof(S));
	memset(match,0,sizeof(match));
}
void dfs(int i)
{
	vis[i] = 1;
	for(int k=0;k<2;k++)
	{
		if(!vis[match[i][k]]) dfs(match[i][k]);
	}
}
void pushUp(int x)
{
	S[x] = S[lx] + S[rx];
}
void update(int p,int d,int l,int r,int x)
{
	if(l==r)
	{
		S[x] += d;
		return;
	}
	if(p<=MID) update(p,d,l,MID,lx);
    else update(p,d,MID+1,r,rx);
    pushUp(x);
}
int query(int L,int R,int l,int r,int x)
{
	if(L<=l && r<=R)
	{
		return S[x];
	}
	int ans = 0;
	if(L<=MID) ans += query(L,R,l,MID,lx);
	if(MID<R) ans += query(L,R,MID+1,r,rx);
	return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf(" %d",&n);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf(" %d %d",&p[i].x,&p[i].y);
		p[i].x += 10001,p[i].y += 10001;
		maxx = max(maxx,max(p[i].x,p[i].y));
	}
	//x
	for(int i=1;i<=n;i++) s[p[i].x].push_back(i);

	for(int i=1;i<=maxx;i++)
	{
		if(s[i].size())
		{
			if(s[i].size()&1) goto L1;
			sort(s[i].begin(),s[i].end(),cmpy);
			for(int j=0;j<s[i].size();j+=2)
			{
				ans += p[s[i][j+1]].y - p[s[i][j]].y;
				match[s[i][j+1]].push_back(s[i][j]);
				match[s[i][j]].push_back(s[i][j+1]);
			}
			s[i].clear();
		}
	}

	//y
	for(int i=1;i<=n;i++) s[p[i].y].push_back(i);

	for(int i=1;i<=maxx;i++)
	{
		if(s[i].size())
		{
			if(s[i].size()&1) goto L1;
			sort(s[i].begin(),s[i].end(),cmpx);
			for(int j=0;j<s[i].size();j+=2)
			{
				ans += p[s[i][j+1]].x - p[s[i][j]].x;
				match[s[i][j+1]].push_back(s[i][j]);
				match[s[i][j]].push_back(s[i][j+1]);
			}
			//s[i].clear();
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(match[i].size()!=2) goto L1;
	}
	//连通
	dfs(1);
	for(int i=1;i<=n;i++) if(!vis[i]) goto L1;
	memset(vis,0,sizeof(vis));
	//判断相交
	for(int i=1;i<=maxx;i++)
	{
		if(s[i].size())
		{
			for(int j=0;j<s[i].size();j+=2)
			{
				int x1 = p[s[i][j]].x;
				int x2 = p[s[i][j+1]].x;
				if(x2-x1>1 && (query(1,x2-1,1,maxx,1) - query(1,x1,1,maxx,1))>0)
					goto L1;
				if(!vis[x1]) update(x1,1,1,maxx,1);
				else update(x1,-1,1,maxx,1);
				if(!vis[x2]) update(x2,1,1,maxx,1);
				else update(x2,-1,1,maxx,1);
				vis[x1] = !vis[x1];
				vis[x2] = !vis[x2];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
	L1: puts("0");
    return 0;
}
