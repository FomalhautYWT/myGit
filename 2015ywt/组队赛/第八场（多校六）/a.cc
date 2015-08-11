#include <iostream>
#include <stdio.h>
using namespace std;
long long dp[200001],a[1000001];
long long n;
void print(long long x){
    for(long long i=1;i<n;i++)
        if(dp[i+x]>0){
            long long p=(x+i)%n+1,q=(x+i-1)%n+1;
            //cout << p <<" " << q << " " << dp[i];
            for(long long j=1;j<=dp[i+x];j++) printf("%I64d %I64d\n",q,p);
        }
    for(long long i=n-1;i>0;i--)
        if(dp[i+x]<0){
            long long p=(x+i)%n+1,q=(x+i-1)%n+1;
            //cout << p <<" " << q << " " << -dp[i];
            for(long long j=1;j<=-dp[i+x];j++) printf("%I64d %I64d\n",p,q);
        }
    return;
}

long long aabs(long long x){
    if(x<0) return -x;
        else return x;
}

int main(){
    long long T;
    scanf("%I64d",&T);
    while(T--){
        long long flag=0;
        scanf("%I64d",&n);
        long long sum=0;
        for(long long i=0;i<n;i++){
            scanf("%I64d",&a[i]);
            sum+=a[i];
        }
        if(sum%n) {puts("NO");continue;}
        sum=sum/n;
        long long tmp=0;
        for(long long i=0;i<n;i++){
            a[i]-=sum;
            a[i+n]=a[i];
            if(a[i]>0) tmp+=a[i];
        }
    if(tmp==0) {printf("YES\n0\n");continue;}
        if(tmp>n) {printf("NO\n");continue;}
        long long ans;
        for(long long i=0;i<n;i++)
        {
            ans=n+1;
     //   cout << a[i] << endl;
            if(a[i]!=0){
            //cout << "haha" << endl;
                dp[i]=0;
                ans=0;
                for(long long j=1;j<n;j++){
                    dp[i+j]=dp[i-1+j]+a[i+j-1];
                    ans+=aabs(dp[i+j]);
                }
            }
            if(ans<=n){
                puts("YES");
                printf("%I64d\n",ans);
                print(i);
                flag=1;
                break;
            }
        }
        if(!flag) printf("NO\n");
    }
}
