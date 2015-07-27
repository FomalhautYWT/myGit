#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[2000000];
struct node{
    int num , fir , ed;
} b[2000000];
int n;
int maxb = 0 , maxi;

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
    {
        scanf("%d",&a[i]);
        if (b[a[i]].num == 0)
        {
            b[a[i]].fir = i;
            b[a[i]].ed = i;
        }
        else{
            b[a[i]].ed = i;
        }
        b[a[i]].num++;
    }
    for (int i = 1; i <= 1000000 ; i ++)
    {
        if (b[i].num > maxb)
        {
            maxb = b[i].num ;
            maxi = i;
        }
        else if (b[i].num == maxb)
        {
            if (b[i].ed - b[i].fir < b[maxi].ed - b[maxi].fir)
            {
                maxb = b[i].num;
                maxi = i;
            }
        }
    }
    printf("%d %d\n",b[maxi].fir,b[maxi].ed);
}
