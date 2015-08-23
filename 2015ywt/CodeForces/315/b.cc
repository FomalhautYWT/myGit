#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>

using namespace std;
vector<int> q;
int a[200000];
int b[200000];
int main()
{
    q.clear();
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
        if (b[a[i]] > 1 || a[i] > n)
            q.push_back(i);
    }
    int now = 0;
    for (int i = 1; i <= n ; i ++)
        if (b[i] == 0)
    {
        a[q[now++]] = i;
    }
    printf("%d",a[1]);
    for (int i = 2; i <= n ; i ++)
        printf(" %d",a[i]);
    puts("");
}
