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
        int gets(){ return this?sz:0;} // ���Ϊ�վͷ���0
        int getls() { return this?ch[0]->gets():0;}
        int getrs() { return this?ch[1]->gets():0;}
    }pool[(MAXN+MAXM)*40],*a[MAXN],*b[MAXN],*c[40],*d[40]; // pool���ܹ��ڵ�����a��b��n������
    int used,amount,left,right;
//ԭ����n����������һ��������ʱn*logn*logS�ĸ��Ӷȣ�ֱ�Ӳ���n*logS����a�����ϲ���
//֮�󵥵������b�����ϲ�����n*logn*logS��b����״����ģʽ�Ĳ�����b��ÿ��Ԫ�ض�Ӧһ���߶����ĸ�
    Node *malloc(Node *root,int w)
    {
        //if(pool[used]==NULL)
            //pool[used]=new Node(); //new����������ڴ�أ�����TLE
        Node *now=&pool[used++];
        if(root==NULL)//b�������ʱ
        {
            now->sz=w;
            now->ch[0]=NULL;//ÿ�θ���ʱҪ��ʼ��
            now->ch[1]=NULL;
        }
        else//a�������ʱ
        {
            now->sz=root->sz+w;
            now->ch[0]=root->ch[0];
            now->ch[1]=root->ch[1];
        }
        return now;
    }
    Node *insert(Node *root,int x,int w,int l,int r)//a�����ϵĲ���
    {
        Node *now=malloc(root,w);
        if(l!=r)
        {
            if(x<=(l+r)/2) now->ch[0]=insert(now->ch[0],x,w,l,l+r>>1);
            else now->ch[1]=insert(now->ch[1],x,w,(l+r>>1)+1,r);
        }
        return now;
    }
    Node *change(Node *root,int x,int w,int l,int r)//b�����ϵĵ������
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
        else // ���k������������ϵĸ�����˵��Ҫ�ҵ������Ҷ�����
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
    void clear(int n,int l,int r)//l��r�������߶������������䣬����ȫ��������ʱ�Ǵ�0����1��ʼ�ţ�����l��0����1
    {
        used=0;
        amount=n;
        left=l;
        right=r;
        for(int i=0;i<=n;++i)// a,b����1-n��
            a[i]=b[i]=NULL;
    }
    void insert(int i,int x,int w)
    {
        a[i]=insert(a[i-1],x,w,left,right);//a[i]��1-i�ĵ���
    }
    int query(int l,int r,int k)//Ҫѯ��[l+1,r]�Ľ������f(r)-f(l)
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
            cmt.insert(i+1,j,1);// i+1��a�����ϸ��µ�λ�ã�j�Ƕ�Ӧ���߶������µ�λ��
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
