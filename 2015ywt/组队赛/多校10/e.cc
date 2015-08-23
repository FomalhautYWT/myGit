#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,w;int c,a,b;
int dp[3000];
bool vis[2010];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&w,&n);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&c,&a,&b);
            memset(vis,0,sizeof(vis));
            for(int j=c;j<=w;j++)
            {
                if(!vis[j-c])
                {
                    if(dp[j-c]+a+b>dp[j])
                    {
                        dp[j]=dp[j-c]+a+b;
                        vis[j]=1;
                    }
                }
                else
                {
                    if(dp[j-c]+a>dp[j])
                    {
                        dp[j]=dp[j-c]+a;
                        vis[j]=1;
                    }
                }
                //cout<<j<<" "<<vis[j]<<" "<<dp[j]<<endl;
            }
        }
        printf("%d\n",dp[w]);
    }
}
