#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<pair<pair<int ,int>,int> > things;
multiset<pair<int ,int> > sj;
int main()
{
	int n , m ;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		things.clear();
		for (int i = 1; i <= n ; i ++)
		{
			int x , y ;
			scanf("%d%d",&x,&y);
			things.push_back(pair<pair<int,int>,int>(pair<int,int>(y,x),1));		
		}
		for	(int i = 1; i <= m ; i ++)
		{
			int x , y ;
			scanf("%d%d",&x,&y);
			things.push_back(pair<pair<int,int>,int>(pair<int,int>(y,x),0));
		}
		sort(things.begin(),things.end());
		long long ans = 0 , ansp = 0 ;
		sj.clear();
		vector<pair<pair<int,int>,int> >::iterator it;
		for (it = things.begin();it!=things.end();it++)
		{
			if (it->second==0)
			{
				sj.insert(pair<int,int>(-it->first.second,-it->first.first));
			}
			else
			{
				multiset<pair<int,int> >::iterator itm;
				itm = sj.lower_bound(pair<int,int>(-it->first.second,-it->first.first));
				if(itm == sj.end()) continue;
				ansp++;
				ans += 500*(-itm->first)+2*(-itm->second);
				sj.erase(itm);
			}
		}
		cout << ansp <<" "<< ans <<endl;
	}
	
}
