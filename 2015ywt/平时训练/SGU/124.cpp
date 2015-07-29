#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<algorithm>
int n;
struct line
{
    int x1 , x2 , y1 , y2;
    line(){}
    line(int _x1,int _x2,int _y1,int _y2)
    {
        x1 = _x1;
        x2 = _x2;
        y1 = _y1;
        y2 = _y2;
    }
}poi[10086];
using namespace std;
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
    {
        scanf("%d%d%d%d",&poi[i].x1,&poi[i].y1,&poi[i].x2,&poi[i].y2);
        if (poi[i].x1 > poi[i].x2) swap(poi[i].x1,poi[i].x2);
        if (poi[i].y1 > poi[i].y2) swap(poi[i].y1,poi[i].y2);
    }
    int xx,yy;
    scanf("%d%d",&xx,&yy);
    int p = 0;
    for (int i = 1; i <= n ; i ++)
    {
        if (poi[i].x1 == poi[i].x2) 
        {
            if (xx == poi[i].x1 && yy >= poi[i].y1 && yy <= poi[i].y2)
            {
                puts("BORDER");
                return 0;
            }
        }
        if (poi[i].y1 == poi[i].y2)
        {
            if (yy == poi[i].y1 && xx >= poi[i].x1 && xx <= poi[i].x2)
            {
                puts("BORDER");
                return 0;
            }
            //cout << poi[i].x1 << " " << poi[i].x2 << " "  << poi[i].y1 << " "<<poi[i].y2 << " " << yy  << " " << xx << endl;
            if (poi[i].y1 > yy && poi[i].x1 < xx && poi[i].x2 >=xx) p++;
        }
    }
    //cout << p << endl;
    if (p & 1)
        puts("INSIDE");
    else
        puts("OUTSIDE");
    return 0;
}
