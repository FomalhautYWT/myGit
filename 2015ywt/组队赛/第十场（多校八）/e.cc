
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

char str[101000];
struct Trie
{
    int next[100005][28],fail[100005],end[100005];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 28;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char s[],int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][s[i]-'a'] == -1)
                next[now][s[i]-'a'] = newnode();
            now = next[now][s[i]-'a'];
        }
        if (end[now] == -1)
            end[now] = 0;
        end[now]++;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < 28;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 28;i++)
                if(next[now][i] == -1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void query(char* buf,int n,int start,int ed)
    {
        int len=ed - start + 1;
        int now=root;
        int ans = 0;
        for(int i=0;i<len;i++)
        {
            now=next[now][buf[i+start]-'a'];
            int temp = now;
            while( temp != root )
            {
                if(end[temp] != -1)
                    ans += end[temp];
                temp = fail[temp];
            }
        }
        printf("%d\n",ans);

    }

};
char qua[2000000];

char stnow[200000];
int qq[200000][2];
Trie ac;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n , m;
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&m);
        ac.init();
        int last = 0;
        memset(qua,0,sizeof(qua));
        for(int i = 0; i < n;i++)
        {
            scanf("%s",stnow);
            int len = strlen(stnow);
            strcat(qua,stnow);
            qq[i][0] = last ;
            qq[i][1] = last + len - 1;
            last = qq[i][1] + 1;
        }
        for (int i = 0; i < m ; i ++)
        {
            scanf("%s",str);
            ac.insert(str,i);
        }
        ac.build();
        for (int i = 0; i < n ; i ++)
        {
            //cout << qu[i] << " : " << endl;
            ac.query(qua,m,qq[i][0],qq[i][1]);
        }
    }
    return 0;
}
1,4,8,13,19
	1, 4, 8, 13, 19, 26, 34, 43, 53, 64, 76, 89, 103, 118, 134, 151, 169, 188, 208, 229, 251, 274, 298, 323, 349, 376, 404, 433, 463, 494, 526, 559, 593, 628, 664, 701, 739, 778, 818,
