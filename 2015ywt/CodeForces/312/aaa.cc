#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
pair<int,int> A[100000],B[100000];
int main()
{
    int n,i,j,a=0,b=0;
    long long s=0,mn;
    cin>>n;
    for(i=0;i<n;i++)
    {
     cin>>j;
     if(j>=0){
         A[a].first=j;cin>>A[a].second;a++;
     }
     else {
         B[b].first=-j;cin>>B[b].second;b++;
     }
    }
   // if(a==0)
    sort(A,A+a);sort(B,B+b);
    mn= min(a,b);
    cout << mn << endl;
      for(j=mn;j>=0;j--)
       {
        s+=A[j].second;
        s+=B[j].second;
    }

    cout<<s;

}
