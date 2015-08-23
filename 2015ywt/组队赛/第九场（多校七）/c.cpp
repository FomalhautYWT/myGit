#pragma comment(linker,"/STACK:16777216")
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
struct edge
{
    int v,next;
}e[300000];
int head[120000],cnt;
long long tim[120000];
int n;
void addedge(int u,int v)
{
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
bool flag;
ll ans;
int x,y;
int siz[120000];
int dep[120000];int maxdep;
int dfs(int u,int fa)
{
    if(flag==0)return 0;
    siz[u]=1;
    int cc=0,big=0;
    int size;
    for(int i=head[u];i!=-1;i=e[i].next)if(e[i].v!=fa)
    {
        dep[e[i].v]=dep[u]+1;
        if(dep[e[i].v]>maxdep)maxdep=dep[e[i].v];
        size=dfs(e[i].v,u);
        //cout<<u<<" "<<size<<" kk"<<endl;

        siz[u]+=size;
        if(size>1) big++;
        else cc++;
    }
    if(big>2)flag=0;
    ans=ans*tim[cc]%mod;
    //cout<<u<<" "<<ans<<endl;
    return siz[u];

}
int main()
{
    int t;
    tim[1]=tim[0]=1;
    for(int i=2;i<=100000;i++)
        tim[i]=tim[i-1]*i%mod;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        cnt=0;
        memset(head,-1,sizeof(head));
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        flag=1;
        ans=1;
        maxdep=dep[1]=1;
        dfs(1,-1);
        //cout<<ans<<endl;
        for(int i=1;i<=maxdep-1;i++)ans=ans*2%mod;
        if(!flag) ans=0;
            printf("Case #%d: %I64d\n",cas,ans);

    }
}
