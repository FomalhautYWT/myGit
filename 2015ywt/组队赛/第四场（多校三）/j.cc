#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int fe,dp1,dp2,v;
};
struct Edge {
    int t,ne;
};
Node a[500001];
Edge b[1000000];
int n,bp,ans;

void putedge(int x,int y) {
    b[bp].t=y;
    b[bp].ne=a[x].fe;
    a[x].fe=bp++;
}
void dfs(int i,int f) {
    vector<pair<int,int> > c;
    int j,p,q;
    for (j=a[i].fe;~j;j=b[j].ne) if (b[j].t!=f) {
        dfs(b[j].t,i);
        if (a[b[j].t].v>a[i].v) {
            a[i].dp1+=a[b[j].t].dp1;
            q=a[b[j].t].dp1;
            p=a[b[j].t].dp1;
        } else {
            a[i].dp2=max(a[i].dp2,a[b[j].t].dp2+1);
            q=0;
            p=a[b[j].t].dp2;
        }
        c.push_back(make_pair(p,q));
    }
    a[i].dp2=max(a[i].dp2,a[i].dp1);
    int sum=1;
    for (j=0;j<c.size();j++) sum+=c[j].second;
    for (j=0;j<c.size();j++) ans=max(ans,sum-c[j].second+c[j].first);
    ans=max(ans,sum);
}
int main() {
    int i,x,y;
    while (scanf("%d",&n)!=EOF) {
        bp=0;ans=0;
        for (i=1;i<=n;i++) {
            scanf("%d",&a[i].v);
            a[i].dp1=a[i].dp2=1;
            a[i].fe=-1;
        }
        for (i=1;i<n;i++) {
            scanf("%d%d",&x,&y);
            putedge(x,y);
            putedge(y,x);
        }
        dfs(1,-1);
        printf("%d\n",ans);
    }
    return 0;
}
