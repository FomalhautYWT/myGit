#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int c[70000][25],b[70000][25],in[30],out[30],sum[30];
int n,m,cas;
struct Node{
    int x,y;
}a[30];
int get(){
    int ans=0;
    int f=1;
    for(int i=1;i<=n;i++){
        ans+=in[i]*f;
        f*=4;
    }
    return ans;

}
int dfs(int v){
    if(v==m) return 1;
    int x=a[v].x,y=a[v].y;
    int ans=0;
    int f=get();
    if(b[f][v]==cas) return c[f][v];
    if(in[x]<sum[x]&&in[y]<sum[y]){
        in[x]++;
        in[y]++;
        ans+=dfs(v+1);
        in[x]--;
        in[y]
            --;

    }
    if(out[x]<sum[x]&&out[y]<sum[y]){
        out[x]++;
        out[y]++;
        ans+=dfs(v+1);
        out[x]--;
        out[y]--;
    }
    b[f][v]=cas;
    return c[f][v]=ans;
}

int main(){
    int T;
    cas=0;
    scanf("%d",&T);
    memset(b,0,sizeof(b));
    while(T--){
        cas++;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            in[i]=0;
            out[i]=0;
            sum[i]=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
            sum[a[i].x]++;
            sum[a[i].y]++;
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            flag=sum[i]%2;
            if(flag) break;
            sum[i]/=2;
        }
        if(flag) printf("0\n");
        else printf("%d\n",dfs(0));
    }
}
