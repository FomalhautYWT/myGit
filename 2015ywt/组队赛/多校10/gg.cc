#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int Scan()     //ÊäÈëÍâ¹Ò
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
const int max_n=200000+10;
const int tree_size=5000000+10;
int n,m,tot;
int a[max_n],ll[max_n],rr[max_n],root[max_n],lef[tree_size],rig[tree_size],key[tree_size],s[tree_size];
void l_rotate(int &t)
{
	int k=rig[t];rig[t]=lef[k];lef[k]=t;
	s[k]=s[t];s[t]=s[lef[t]]+s[rig[t]]+1;
	t=k;
}
void r_rotate(int &t)
{
	int k=lef[t];lef[t]=rig[k];rig[k]=t;
	s[k]=s[t];s[t]=s[lef[t]]+s[rig[t]]+1;
	t=k;
}
void maintain(int &t,int flag)
{
	if (flag)
	{
		if (s[lef[lef[t]]]>s[rig[t]]) r_rotate(t);
		else if (s[rig[lef[t]]]>s[rig[t]]) l_rotate(lef[t]),r_rotate(t);
		else return;
	} else
	{
		if (s[rig[rig[t]]]>s[lef[t]]) l_rotate(t);
		else if (s[lef[rig[t]]]>s[lef[t]]) r_rotate(rig[t]),l_rotate(t);
		else return;
	}
	maintain(lef[t],1);maintain(rig[t],0);
	maintain(t,1);maintain(t,0);
}
void insert(int &t,int x)
{
	if (t==0)
	{
		t=++tot;
		lef[t]=rig[t]=0;
		s[t]=1;key[t]=x;
		return;
	}
	++s[t];
	if (x < key[t]) insert(lef[t],x);else insert(rig[t],x);
	maintain(t,x<key[t]);
}
int Delete(int &t,int x)
{
	s[t]--;
	if (key[t]==x || x <key[t] && lef[t]==0 || x>key[t] && rig[t]==0)
	{
		int tmp=key[t];
		if (lef[t]==0 || rig[t]==0) t=lef[t]+rig[t];
		else key[t]=Delete(lef[t],x+1);
		return tmp;
	}
	if (x<key[t]) return Delete(lef[t],x);
	return Delete(rig[t],x);
}
int ranka(int t,int x)
{
	if (t==0) return 0;
	if (x<=key[t]) return ranka(lef[t],x);
	return s[lef[t]]+1+ranka(rig[t],x);
}
void build(int t,int l,int r)
{
	ll[t]=l;rr[t]=r;root[t]=0;
	if (l==r) return ;
	int mid=l+r >> 1;
	build(t+t,l,mid);
	build(t+t+1,mid+1,r);
}
void ins(int t,int pos,int x)
{
	insert(root[t],x);
	if (ll[t]==rr[t]) return;
	int mid=ll[t]+rr[t] >> 1;
	if (pos <=mid) ins(t+t,pos,x);
	else ins(t+t+1,pos,x);
}
void del(int t,int pos,int x)
{
	Delete(root[t],x);
	if (ll[t]==rr[t]) return ;
	int mid=ll[t]+rr[t] >> 1;
	if (pos <=mid ) del(t+t,pos,x);
	else del(t+t+1,pos,x);
}
int get_kth(int t,int l,int r,int x)
{
	if (l<=ll[t] && r>=rr[t]) return ranka(root[t],x);
	int ans=0;
	int mid=ll[t]+rr[t] >> 1;
	if (l<=mid) ans+=get_kth(t+t,l,r,x);
	if (r>mid ) ans+=get_kth(t+t+1,l,r,x);
	return ans;
}
void init()
{
	tot=0;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	for (int i=1;i<=n;i++)
	ins(1,i,a[i]);
}
int query(int l,int r,int k)
{
	int p=-1,q=1000000000+1,mid;
	while (p+1!=q)
	{
		mid=(p+q) >> 1;
		if (get_kth(1,l,r,mid)<k) p=mid;else q=mid;
	}
	return p;
}

void solve()
{
	int str;
	int st,en,k,delta;
	for (int i=1;i<=m;i++)
	{
		str = Scan();
		if (str==2)
		{
		    st = Scan();
		    en = Scan();
		    k = Scan();
			//scanf("%d%d%d",&st,&en,&k);
			printf("%d\n",query(st,en,k));
		}else
		{
		    k = Scan();
		    delta = Scan();
			//scanf("%d%d",&k,&delta);
			del(1,k,a[k]);
			a[k]=delta;
			ins(1,k,a[k]);
		}
	}
}
int main()
{
	int M;
	while (scanf("%d",&n)!=EOF)
	{
		init();
		m = Scan();
		solve();
	}
//	system("pause");
	return 0;
}
