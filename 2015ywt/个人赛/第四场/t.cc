#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct sq
{
	int lef,rig,len;
}seg[50];
int main()
{
	int n;
	while (cin >> n,n)
	{
		for (int i=0;i<n;i++)
		{
			cin >> seg[i].len;
			seg[i].lef=0;
			for (int j=0;j<i;j++)

			{
			    seg[i].lef=max(seg[i].lef,seg[j].rig-abs(seg[i].len-seg[j].len));
			    cout << seg[i].lef << endl;
			}
			seg[i].rig=seg[i].lef+seg[i].len*2;
		}

		for (int i=1;i<n;i++)
		for (int j=0;j<i;j++)
		if (seg[i].lef<seg[i].rig)
		{
			if (seg[i].len>seg[j].len && seg[i].lef<seg[j].rig)
			seg[j].rig=seg[i].lef;
			else if(seg[i].len<seg[j].len && seg[i].lef<seg[j].rig)
			seg[i].lef=seg[j].rig;
		}
		for (int i=0;i<n;i++)
		if (seg[i].lef<seg[i].rig) cout << i+1 << " ";
		cout << endl;
	}
//	system("pause");
}
