#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int bom[500];
int top[500];
int len[500];
int n;
void seek(int x ,int y)
{
    if (top[x] < bom[x]) return;
    if (len[x] > len[y] && bom[x] < top[y])
        top[y] = bom[x];
    else if (len[x] < len[y] && bom[x] < top[y])
        bom[x] = top[y];
    //cout << x << " "<< y << endl << " "<< bom[x] << " " << top[x] << " " << endl << " "<< bom[y] << " " << top[y] << " " << endl;;

}
bool canSee(int p)
{
    if (bom[p] < top[p]) return true;
    return false;
}
int main()
{
    while (scanf("%d",&n),n)
    {
        for (int i=1;i<=n;i++)
		{
			scanf("%d",&len[i]);
			bom[i] = 0;
			for (int j=1;j<i;j++)
				bom[i]=max(bom[i],top[j]-abs(len[i]-len[j]));
			top[i]=bom[i]+len[i]*2;
		}
		//for (int i = 1; i <= n ; i ++)
		//cout << bom[i] << " " << top[i] << endl;
        for (int i = 1 ; i <= n ; i ++)
            for (int j = 1 ; j < i ; j ++)
                seek(i , j);

        int flag = 0;
    //    for (int i = 1; i <= n ; i ++)
     //       cout << bom[i] << " " << top[i] << endl;
        for (int i = 1; i <= n ; i ++)
        {
       //     cout << bom[i] << " "<< top[i] << " " << canSee(i)  << endl;
            if  (canSee(i))
            {
                if (flag == 0)
                {
                    flag = 1;
                    printf("%d",i);
                }
                else
                {
                    printf(" %d",i);
                }
            }
        }
        puts("");
    }
}
