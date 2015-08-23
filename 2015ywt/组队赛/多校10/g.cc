#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define MAXM 100005

class CMT
{
private:
    struct Node
    {
        int sz;
        Node *ch[2];
        Node()
        {
            sz=0;ch[0]=ch[1]=NULL;
        }
        Node(int _sz,Node *ll,Node *rr)
        {
            sz=_sz;ch[0]=ll;ch[1]=rr;
        }
        int gets(){ return this?sz:0;} // 如果为空就返回0
        int getls() { return this?ch[0]->gets():0;}
        int getrs() { return this?ch[1]->gets():0;}
    }pool[(MAXN+MAXM)*40],*a[MAXN],*b[MAXN],*c[40],*d[40]; // pool是总共节点数，a，b是n个数，
    int used,amount,left,right;
//原来有n个数，避免一个个插入时n*logn*logS的复杂度，直接插入n*logS，在a数组上操作
//之后单点更新在b数组上操作，n*logn*logS，b是树状数组模式的操作，b上每个元素对应一棵线段树的根
    Node *malloc(Node *root,int w)
    {
        //if(pool[used]==NULL)
            //pool[used]=new Node(); //new出来后放在内存池，避免TLE
        Node *now=&pool[used++];
        if(root==NULL)//b数组操作时
        {
            now->sz=w;
            now->ch[0]=NULL;//每次复用时要初始化
            now->ch[1]=NULL;
        }
        else//a数组操作时
        {
            now->sz=root->sz+w;
            now->ch[0]=root->ch[0];
            now->ch[1]=root->ch[1];
        }
        return now;
    }
    Node *insert(Node *root,int x,int w,int l,int r)//a数组上的插入
    {
        Node *now=malloc(root,w);
        if(l!=r)
        {
            if(x<=(l+r)/2) now->ch[0]=insert(now->ch[0],x,w,l,l+r>>1);
            else now->ch[1]=insert(now->ch[1],x,w,(l+r>>1)+1,r);
        }
        return now;
    }
    Node *change(Node *root,int x,int w,int l,int r)//b数组上的单点更新
    {
        if(root==NULL) root=malloc(NULL,0);
        if(l!=r)
        {
            if(x<=(l+r>>1)) root->ch[0]=change(root->ch[0],x,w,l,l+r>>1);
            else root->ch[1]=change(root->ch[1],x,w,(l+r>>1)+1,r);
        }
        root->sz+=w;
        return root;
    }
    int query(int k,int lc,int ld,int l,int r)
    {
        if(l==r) return l;
        int sum=0;
        for(int i=0;i<lc;++i)
            if(c[i])
            sum-=c[i]->getls();
        for(int i=0;i<ld;++i)
            if(d[i])
            sum+=d[i]->getls();
        if(k<=sum)
        {
            for(int i=0;i<lc;++i)
                if(c[i])
                c[i]=c[i]->ch[0];
            for(int i=0;i<ld;++i)
                if(d[i])
                d[i]=d[i]->ch[0];
            return query(k,lc,ld,l,l+r>>1);
        }
        else // 如果k大于在左儿子上的个数，说明要找的数在右儿子上
        {
            for(int i=0;i<lc;++i)
                if(c[i])
                c[i]=c[i]->ch[1];
            for(int i=0;i<ld;++i)
                if(d[i])
                d[i]=d[i]->ch[1];
            return query(k-sum,lc,ld,(l+r>>1)+1,r);
        }
    }

public:
    void clear(int n,int l,int r)//l，r是整棵线段树的左右区间，根据全部数排序时是从0还是1开始排，决定l是0还是1
    {
        used=0;
        amount=n;
        left=l;
        right=r;
        for(int i=0;i<=n;++i)// a,b都是1-n的
            a[i]=b[i]=NULL;
    }
    void insert(int i,int x,int w)
    {
        a[i]=insert(a[i-1],x,w,left,right);//a[i]是1-i的叠加
    }
    int query(int l,int r,int k)//要询问[l+1,r]的结果，即f(r)-f(l)
    {
        int lc=0,ld=0;
        c[lc++]=a[l];
        d[ld++]=a[r];
        for(int x=l;x;x-=x&(-x))
            c[lc++]=b[x];
        for(int x=r;x;x-=x&(-x))
            d[ld++]=b[x];
        return query(k,lc,ld,left,right);
    }
    void change(int i,int x,int w)
    {
        while(i<=amount)
        {
            b[i]=change(b[i],x,w,left,right);
            i+=i&(-i);
        }
    }
}cmt;

struct CMD
{
    int x,y,k;
    char ch;
}cmd[MAXM];
int a[MAXN],b[MAXM+MAXN],tot,n,m;

int main ()
{

    while(scanf("%d",&n)!=EOF)
    {
        tot=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            b[tot++]=a[i];
        }
        scanf("%d",&m);
        for(int i=0;i<m;++i)
        {
            scanf(" %c",&cmd[i].ch);
            if(cmd[i].ch=='2')
                scanf("%d%d%d",&cmd[i].x,&cmd[i].y,&cmd[i].k);
            else {
                    scanf("%d%d",&cmd[i].x,&cmd[i].k);
                b[tot++]=cmd[i].k;
            }
        }
        sort(b,b+tot);
        int cnt=1;
        for(int i=1;i<tot;++i)
            if(b[i]!=b[i-1])
            b[cnt++]=b[i];
        tot=cnt;

        cmt.clear(n,0,tot-1);
        for(int i=0;i<n;++i)
        {
            int j=lower_bound(b,b+tot,a[i])-b;
            cmt.insert(i+1,j,1);// i+1是a数组上更新的位置，j是对应的线段树更新的位置
        }
        for(int i=0;i<m;++i)
        {
            if(cmd[i].ch=='2')
            {
                printf("%d\n",b[cmt.query(cmd[i].x-1,cmd[i].y,cmd[i].k)]); //f[l,r]=f[1,r]-f[1,l-1]
            }
            else
            {
                int j=lower_bound(b,b+tot,a[cmd[i].x-1])-b;
                cmt.change(cmd[i].x,j,-1);
                a[cmd[i].x-1]=cmd[i].k;
                j=lower_bound(b,b+tot,a[cmd[i].x-1])-b;
                cmt.change(cmd[i].x,j,1);
            }
        }
    }
    return 0;
}
