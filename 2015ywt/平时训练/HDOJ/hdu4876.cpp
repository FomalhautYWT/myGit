#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int ans ;
int n , k , l ;
int now [10];
bool visit[130];
bool v[22];
int vh[200];
int now1[15];
int a[23];
bool check()
{
    memset(visit,0,sizeof(visit));
    visit[0] = 1;
    vh[1] = 0;
    int size = 1;
    
    for(int i = 1 ; i <= k ; i ++)
    {
        int p = size;
        for (int j = 1; j <= p ; j ++)
        {
            int temp = now[i] ^ vh[j];
            if (!visit[temp])
            {
                visit[temp] = 1;
                vh[++size] = temp;
            }
        }
    }
    for (int i = l ; i <= ans + 1; i ++)
    if (!visit[i]) return 0;
    return 1;
}

void run()
{
    memset(visit,0,sizeof(visit));
    for (int i = 1; i <= k ; i ++)
    now1[i+k] = now1[i];
    for (int i = 1; i <= k ; i ++)
    {
        int temp = 0;
        for(int j = 1;j <= k ; j ++)
        {
            /*int temp = 0;
            for (int kq = i ; kq <= i+j-1;kq++)
            {
                temp^= now1[kq];
            }
            visit[temp] = 1;
            /*if (temp == 7)
            {
                for (int i = 1 ; i <= k ; i ++)
                cout << now[i] << " " ;
                cout << endl;
                //system("pause");
            }*/
            temp ^= now1[i+j-1];
            visit[temp] = 1;
            
        }
    }
    
}

void dfs2()
{
    for (int i = 1; i <= k ; i ++)
    now1[i] = now[i] ;
    sort(now1+1,now1+k+1);
    /*for (int i = 1; i <= k ; i ++)
    cout << now[i] << " " ;
    cout << endl;*/
    do
    {
        run();
        for (int i = l ; i < 129 ; i ++)
            if (!visit[i]) {
                ans = max(ans , i-1);
                break;
            }
    }
    while(next_permutation(now1+1,now1+k+1));
}

int maxbit(int p)
{
    int k = 0;
    while (p)
    {
        k++;
        p = p >> 1;
    }
    return k;
}
void dfs(int num ,int xx ,int maxb)
{
    //cout <<"!"<<endl;
    //if ( num > 1 && maxb < maxbit( ans ) ) return ;
    if ( k - num > n - xx +1) return ;
    if ( num == k )
    {
        //cout <<"incheck"<<endl;
        if (!check()) return ;
        //cout <<"aftercheck"<<endl;
        dfs2();
        return ;
    }

    for (int i = xx; i <= n ; i ++)
    {        
        if (!v[i])
        {
            now[num+1] = a[i];
            v[i] = 1;
            if (num == 1) dfs(num + 1, i + 1, maxbit(a[i]));
            else dfs(num+1 , i + 1 , maxb);
            v[i] = 0;
            now[num+1] = 0;
        }
    }
    
}
bool cmp(const int &a,const int &b)
{
    return a>b;
}


int solve()
{
    memset(v,0,sizeof(v));
    dfs(0 , 1 , 0);
}

int main()
{
    /*freopen("1005.in","r",stdin);
    freopen("1005.out","w",stdout);*/
    while(scanf("%d%d%d",&n,&k,&l)!=EOF)
    {
        ans = 0 ;
        //cout <<"!"<<endl;
        for (int i = 1; i <= n ; i ++)
        scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        
        //cout <<"!"<<endl;
        solve();
        //cout <<"!"<<endl;
        if (ans>l-1) printf("%d\n",ans);
        else puts("0");
    }
//    fclose(stdin);
//    fclose(stdout);
}


