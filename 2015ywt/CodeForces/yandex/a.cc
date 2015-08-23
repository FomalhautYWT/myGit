#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int shi[9] = {0 , 1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000};
int n;
int a[100];

int nowans;
void dfs(int ti , int ans)
{
    //cout << " ! " << ti << " " << ans << endl;
    //system("pause");
    if (ti == n)
    {
        if (ans > nowans)
            nowans = ans;
        return;
    }
    ans += a[ti+1];
    int tans = ans;
    int tmp[10];
    memset(tmp,0,sizeof(tmp));
    while(tans)
    {
        tmp[++tmp[0]] = tans % 10;
        tans /= 10;
    }

    sort(tmp + 1 , tmp + tmp[0] + 1);
    do{
        int tmpans = 0;
        for (int i = 1; i <= tmp[0] ; i ++)
        {
            tmpans += tmp[i] * shi[i];
        }
        //if (ti == 3)
        //cout << ti <<" "<< tmpans << endl;
        dfs(ti + 1 , tmpans);
    }while(next_permutation(tmp + 1 , tmp + tmp[0] + 1));
}
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n ; i ++)
        scanf("%d",&a[i]);
    dfs(0,0);
    printf("%d\n",nowans);
}
