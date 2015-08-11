#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxv=2e5+50;
int x[maxv],y[maxv];
set<P> s;
set<P>::iterator it;
int n,q;
char ch[2];
int main(){
    ///freopen("/home/files/CppFiles/in","r",stdin);
    cin>>n>>q;
    s.insert(P(0,0));
    s.insert(P(n+1,q+1));
    for(int i=1;i<=q;i++){
        scanf("%d%d%s",&x[i],&y[i],ch);
        if(ch[0]=='U'){
            it=s.lower_bound(P(y[i],-1));
            if(it->first>y[i]) it--;
        }else{
            it=s.upper_bound(P(y[i],-1));
        }
        if(it->first==y[i]){
            puts("0");
            continue;
        }
        s.insert(P(y[i],i));
        if(ch[0]=='U'){
            printf("%d\n",y[i]-y[it->second]);
            y[i]=y[it->second];
        }else{
            printf("%d\n",x[i]-x[it->second]);
            x[i]=x[it->second];
        }
    }
    return 0;
}
