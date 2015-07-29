#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
using namespace std;
int A , B , N , cnt;
pair<int ,int > ans[10020];
int main()
{
    scanf("%d%d%d",&N , &A , &B);
    A = A % N ;
    B = B % N ;
    int a = A % N  , b = B % N;
    ans[++cnt].first = A;
    ans[ cnt ].second = B;

    while ( (a + A) % N != A || (b + B) % N != B )
    {
        a = ( a + A ) % N ;
        b = ( b + B ) % N ;
        ans[++cnt].first = a;
        ans[cnt ].second = b;
    }
    sort(ans + 1 , ans + cnt + 1);
    printf("%d\n", cnt);
    for (int i = 1 ; i <= cnt ; i ++)
    {
        printf("%d %d\n",ans[i].first , ans[i].second);
    }
    return 0;
}
