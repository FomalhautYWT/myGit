#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define N 363000
int factory[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
const int start = 46233;
int vis[N];
struct node{char next[N],ans[N];int ind,z;
}s;
int wz[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char dir[4]={'u','r','d','l'};
queue<node>q;
int get_hash(char s[])             //康托
{
	int sum=0;
	for(int i=0;i<9;i++)
	{
		int cnt=0;
		for(int j=i+1;j<9;j++)
		{
			if(s[i]>s[j])cnt++;
		}
		sum+=cnt*factory[9-i-1];
	}
	return sum;
}
void change(char s[],int i,int j)    //上下移动的时候换字符串位置
{
	char temp=s[i];
	     s[i]=s[j];
	     s[j]=temp;
}
int bfs()
{
	memset(vis,0,sizeof(vis));
	node a,b;
	for(int i=0;i<9;i++)
	a.next[i]=s.next[i];
	vis[get_hash(a.next)]=1;          //初始值
	a.ind=0;a.z=s.z;
	while(!q.empty())q.pop();
	q.push(a);
	int cnt=0;
	while(!q.empty())
	{
		b=q.front();q.pop();
		if(get_hash(b.next)==start)
		{
			for(int i=0;i<b.ind;i++)             //最后输出
			   cout<<b.ans[i];
			   cout<<endl;
			return 1;
		}
		for(int i=0;i<4;i++)
		{
		    int nx,ny,nz;
		    nx=b.z/3+wz[i][0];ny=b.z%3+wz[i][1];
			if(nx<0||nx>=3||ny<0||ny>=3)continue;
			a.z=3*nx+ny;a.ind=b.ind;
			memcpy(a.ans,b.ans,sizeof(b.ans));
		    memcpy(a.next,b.next,sizeof(b.next));
		    if(a.z>=0&&a.z<9)                     //满足第一步条件的移动
		    {
		       change(a.next,b.z,a.z);
		       int tmp=get_hash(a.next);
		       if(vis[tmp]==0)                   //满足第二步条件的移动
		       {
		          a.ans[a.ind]=dir[i];
		          a.ind=a.ind+1;                //答案移动方向的记录
		       	  vis[tmp]=1;
		       	  q.push(a);
			   }
			}
		}
	}
	return -1;
}
int main()
{
    char ch[100];
	while(gets(ch))
	{
         int p=0;int len=strlen(ch);
         for(int i=0;i<len;i++)
         {
         	  if(ch[i]=='x')
         	  s.next[p++]='0',s.z=p-1;
			  else if(ch[i]!=' ')
         	  s.next[p++]=ch[i];
         }
		 int tmp=bfs();
		 if(tmp==-1)
		 printf("unsolvable\n");
	}
	return 0;
}
