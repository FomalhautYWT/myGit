#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m,limit;
const int maxn=500100;
const long long inf=100000000000LL;
long long a[maxn];
#define debug 0
long long max(long long a,long long b,long long c ,long long d)
{
    long long ans = a;
    if (b > ans) ans = b;
    if (c > ans) ans = c;
    if (d > ans) ans = d;
    return ans;
}
struct node
{
	long long opt,ljro,lorj,ljrj,loro;
	void print()
	{
	    cout << opt << " " << ljro << " " << lorj << " " << ljrj << " " << loro << endl;
	}
}tree[maxn];
void init()
{

	scanf("%I64d%I64d",&n,&m);
	limit=1;
	while (limit <n) limit=limit << 1;
	for (int i=0;i<=limit << 1;i++) a[i]=-inf;
	for (int i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
}
void update(node &x,node ls,node rs)
{
	x.ljrj = max(ls.ljrj+rs.lorj,ls.ljro+rs.ljrj);
	x.ljrj = max(x.ljrj,ls.ljrj,rs.ljrj,-inf);
	x.ljro = max(ls.ljrj+rs.loro,ls.ljro+rs.ljro);
	x.ljro = max(x.ljro,ls.ljro,rs.ljro,-inf);
	x.lorj = max(ls.lorj+rs.lorj,ls.loro+rs.ljrj);
	x.lorj = max(x.lorj,ls.lorj,rs.lorj,-inf);
	x.loro = max(ls.lorj+rs.loro,ls.loro+rs.ljro);
	x.loro = max(x.loro,ls.loro,rs.loro,-inf);
	x.opt = max(x.ljrj,x.ljro,x.lorj,x.loro);
}
void build(long long x,long long ll,long long rr)
{
	long long ls=x << 1, rs=ls+1;
	if (ll==rr)
	{
	    if (ll & 1)
	    {
	        tree[x].ljrj = a[ll];
	        tree[x].loro = tree[x].ljro = tree[x].lorj = -inf;
	    }
	    else if ((ll & 1) == 0)
        {
            tree[x].loro = a[ll];
            tree[x].ljrj = tree[x].ljro = tree[x].lorj = -inf;
        }
		tree[x].opt=a[ll];
		return ;
	}
	long long mid=ll+rr >> 1;
	build(ls,ll,mid);build(rs,mid+1,rr);
	update(tree[x],tree[ls],tree[rs]);

}
node ask(long long x,long long ll,long long rr,long long l,long long r)
{
	long long ls=x << 1,rs=ls+1;
	if (ll==l && rr==r) return tree[x];
	long long mid=ll+rr >> 1;
	node p,q,ans;
	if (mid>=r) ans=ask(ls,ll,mid,l,r);
	else if (l>mid) ans=ask(rs,mid+1,rr,l,r);
	else
	{
		p=ask(ls,ll,mid,l,mid);
		q=ask(rs,mid+1,rr,mid+1,r);
		update(ans,p,q);
	}
	return ans;
}
void modify(long long x,long long ll,long long rr,long long k,long long d)
{
	long long ls=x << 1,rs=ls+1,mid=ll+rr >> 1;
	if (ll==rr)
	{
		if (ll & 1)
	    {
	        tree[x].ljrj = d;
	        tree[x].loro = tree[x].ljro = tree[x].lorj = -inf;
	    }
	    else if ((ll & 1) == 0)
        {
            tree[x].loro = d;
            tree[x].ljrj = tree[x].ljro = tree[x].lorj = -inf;
        }
		tree[x].opt=d;return ;
	}
	if (k<=mid) modify(ls,ll,mid,k,d);
	else modify(rs,mid+1,rr,k,d);
	update(tree[x],tree[ls],tree[rs]);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas --)
    {
        init();
        build(1,1,limit);
        long long s,p,q;
        for (int i=1;i<=m;i++)
        {
            scanf("%I64d%I64d%I64d",&s,&p,&q);
            if (s == 0) printf("%I64d\n",ask(1,1,limit,p,q).opt);
            else modify(1,1,limit,p,q);
            if (debug) for (int i = 1; i <= 15 ; i ++)
            {
                tree[i].print();
            }
        }

    }
	return 0;
}


