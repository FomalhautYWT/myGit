#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[50][51];
bool a[50][50];
int n,m,ans;

void cal() {
    for (int k=1-m;k<=n-1;k++) {
        bool flag=false;
        for (int i=max(0,k),j=i-k;i<n;i++,j++) {
            if (a[i][j]) {
                if (flag==false) ans++;
                flag=true;
            } else flag=false;
        }
    }
}
int main() {
    int t,i,j;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%s",s[i]);
        ans=0;
        m=strlen(s[0]);
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                if (s[i][j]=='R'||s[i][j]=='G') a[i][j]=true;
                else a[i][j]=false;
        cal();
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                if (s[i][j]=='B'||s[i][j]=='G') a[i][m-j-1]=true;
                else a[i][m-j-1]=false;
        cal();
        printf("%d\n",ans);
    }
    return 0;
}
