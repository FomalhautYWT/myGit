#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    int key , size , isOn , onGcd , offGcd;
    node * ch[2] , * p;
    bool dir();
    void set(node * , bool);
    void update();
    void relax();
    void app_turn();
}*null;
struct splaytree
{
    node *root , *now;
    node data[max_n];
    splaytree()
    {
        now = data;
        root = built(1 , n + 2);
        root -> p = null;
    }
    void rot(node * t)
    {
        node * p = t->p ;
        bool d = t->dir();
        p->set(t->ch[!d],d);
        p->p->set(t,p->dir());
        t->set(p,!d);
        p->update();
        if (root == p) root = t;
    }
    void splay(node * t,node *f = null)
    {
        t->relax();
        for (t->relax();t->p!=f;)
        {
            if (t->p->p==f)rot(t);
            else t->dir() == t->p->dir()?(rot(t->p),rot(t)) : (rot(t),rot(t));

        }
        t->update();
    }
    node *new_node(int x , bool isOn)
    {
        now->size = 1;
        now->key=x;
        now->isOn = isOn;
        if (isOn) onGcd = x , offGcd = -1;
        else offGcd = x , onGcd = -1;
        now->p=now->ch[0]=now->ch[1] = null;
        return now ++;
    }
    node *get_kth(int x)
    {
        node *t(root);int cnt(0) , now;
        while (1)
        {

        }
    }
};
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        null = new node;
        null->size = 0;

        for (int i = 2 ; i <= n + 1 ; i ++ )
            scanf("%d",&a[i]);
        splay = new splayree();

    }
}
