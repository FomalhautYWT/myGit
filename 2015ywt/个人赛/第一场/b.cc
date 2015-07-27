#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[20000];

int n ,m;

struct node
{
    int fir , sec , dis;
}vc[20000];
bool cmp ( node a ,node b)
{
    return a.dis < b.dis;
}
int root ( int p )
{
    if (f[p] == p) return f[p];
    p = root(f[p]);
    return p;
}
void combine(int a ,int b)
{
    f[root(a)] = f[root(b)];
}
int ans;
int main()
{
    while (scanf("%d",&n))
    {
        m = 0;
        ans = 0;
        memset(vc,0,sizeof(vc));

        if (n == 0) break;
        for (int i = 1; i < n ; i ++)
        {
            char ch ;
            int p , now;
            int d , tar;
            scanf(" %c %d",&ch , &p);
            now = ch - 'A' + 1;
            for (int j = 1; j <= p ; j ++)
            {
                scanf(" %c %d",&ch,&d);
                tar = ch - 'A' + 1;
                vc[++m].fir = now;
                vc[m].sec = tar;
                vc[m].dis = d;
                //cout <<m << " " <<  vc[m].fir << " " << vc[m].sec << " " << vc[m].dis << endl;
            }


        }
        //cout <<"!"<<endl;
        for (int i = 1; i <= 26 ; i ++)
        {
            f[i] = i;
        }
        sort(vc+1,vc+m + 1,cmp);

        for (int i = 1; i <= m ; i ++)
        {
            //cout <<"r " << vc[i].fir << " " << vc[i].sec << endl;
            if (root(vc[i].fir) == root(vc[i].sec))
                continue;
            combine(vc[i].fir,vc[i].sec);
            ans += vc[i].dis;
            //cout << vc[i].dis << " !!! " << endl;
        }
        printf("%d\n",ans);
    }
}
