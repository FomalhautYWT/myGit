#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string str;
int k;
int leng;
char ans[5009];
int cnt;
bool flag = false;
int f[5008][5008];
struct node
{
    int ok;
    node* ch[2];
    node():ok(0)
    {
        memset(ch, 0 , sizeof(ch));
    }
}* root;
void add( int x )
{
    node * u = root ;
    for (int t = x ; t < leng ; t ++)
    {
        if ( ! ( u -> ch[str[t] - 'a']))
            u -> ch[str[t] - 'a'] = new node();
        u = u -> ch[str[t] - 'a'];
        if ( f[x][t] )
        {
            u->ok ++;
            //cout <<x <<"!"<<t << endl;
        }
    }
}
void dfs( node * t , int d )
{
    //cout << t->ok;

    if (flag) return;

    //cout <<"!"<< t->ok << endl;
    if (t->ok)
    {
        cnt += t->ok;
        if (cnt >= k)
        {
            ans[d] = '\0';
            printf("%s\n",ans);
            flag = true;
            return;
        }
    }
    for (int i = 0 ; i <= 1 ; i ++)
    {
        if ( ! (t-> ch[i]) ) continue;
        ans[d] = (char) ( i + 'a' );
        dfs(t->ch[i],d + 1);
    }
}
int main()
{
    cin >> str;
    cin >> k;
    root = new node();
    leng = str.length();
    for (int l = 1 ; l <= leng ; l ++)
    {
        for (int i = 0 ; i + l - 2 <= leng ; i ++)
        {
            int j = i + l - 1;
            if (l < 5)
                f[i][j] = (str[i] == str[j]);
            else
                f[i][j] = f[i + 2][j - 2] && (str[i] == str[j]);
        }
    }

    for (int i = 0 ; i < leng ; i ++) add(i);
    cnt = 0;
    flag = false;
    dfs(root , 0);

    return 0;
}
