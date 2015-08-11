#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N=1<<18;
const int M=2000;
const double PI=acos(-1.0);

struct Complex {
	double x,y;
	Complex(double xx=0,double yy=0):x(xx),y(yy) {}
	friend Complex operator + (const Complex &a,const Complex &b) {
		return Complex(a.x+b.x,a.y+b.y);
	}
	friend Complex operator - (const Complex &a,const Complex &b) {
		return Complex(a.x-b.x,a.y-b.y);
	}
	friend Complex operator * (const Complex &a,const Complex &b) {
		return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
	}
};

char s1[N],s2[N];
int ls1,ls2;
int res[101][N];
Complex a[N],b[N];
bool flag=false;

void FFT(Complex a[],int n,int oper) {
	if (flag) printf("%d\n",n);
	for (int i=1,j=0;i<n;i++) {
		for (int s=n;j^=s>>=1,~j&s;);
		if (i<j) swap(a[i],a[j]);
	}
	if (flag) printf("aaa\n");
	for (int m=1;m<n;m<<=1) {
		if (flag) printf("--%d\n",m);
		if (flag&&m>256) return;
		double p=PI/m*oper;
		Complex w=Complex(cos(p),sin(p));
		int tmp=0;
		for (int i=0;i<n;i+=m<<1) {
			Complex unit=1;
			for (int j=0;j<m;j++) {
				Complex &x=a[i+j+m],&y=a[i+j],t=unit*x;
				x=y-t;
				y=y+t;
				unit=unit*w;
				tmp++;
			}
		}
		if (flag) printf("ccc %d\n",tmp);
	}
	if (flag) printf("aaa\n");
	if (oper==-1)
		for (int i=0;i<n;i++) a[i].x/=n;
	if (flag) printf("aaa\n");
}

void init() {
	for (int i=0;i<ls2;i++)
		if (s2[i]=='1') b[ls2-i-1]=1;
		else if (s2[i]=='0') b[ls2-i-1]=-1;
	FFT(b,N,1);
	for (int i=0;i<ls1;i+=M) {
		if (i<36) continue;
		if (ls1>100) {
			printf("%d\n",i);
			if (i/M>37) return;
		}
		for (int j=0;j<M;j++)
			if (s2[i+j]=='1') a[j]=1;
			else if (s2[i+j]=='0') a[j]=-1;
		if (i/M==37) flag=true;
		FFT(a,N,1);
		for (int j=0;j<N;j++) a[j]=a[j]*b[j];
		FFT(a,N,-1);
		if (flag) printf("bbb %d\n",i);
		int *aa=res[i/M];
		for (int j=0;j<N;j++) aa[j]=a[j].x+0.5;
	}
}
int solve(int p1,int p2,int len) {
	int ans=0,i;
	for (i=0;i<len&&(p1+i)%M!=0;i++)
		if (s1[p1+i]!=s2[p2+i]) ans++;
	for (;i+M<len;i+=M)
		ans+=(M-res[(p1+i)/M][ls2-p2-i+1])/2;
	for (;i<len;i++)
		if (s1[p1+i]!=s2[p2+i]) ans++;
	return ans;
}
int main() {
	int q,p1,p2,len;
	scanf("%s%s",s1,s2);
	ls1=strlen(s1);
	ls2=strlen(s2);
	if (ls1>100)
		printf("%d %d\n",ls1,ls2);
	init();
	//if (ls1>100)
		//printf("aaa\n");
	scanf("%d",&q);
	while (q--) {
		scanf("%d%d%d",&p1,&p2,&len);
		if (ls1<100)
			printf("%d\n",solve(p1,p2,len));
	}
	return 0;
}
