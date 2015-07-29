#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>

#define pi acos(-1)

using namespace std;
const int N = 200;
int n , num1 , num2 ;
double degree;
struct Node
{
    double x , y ;
} v1 , v2 , v[N] , p;

void rotated_point(Node& origin,Node& f,Node &t,double len,double deg)
{
     double x1=f.x-origin.x; double y1=f.y-origin.y;
     t.x=len*(x1*cos(deg)-y1*sin(deg));
     t.y=len*(x1*sin(deg)+y1*cos(deg));
     t.x+=origin.x;    t.y+=origin.y;
     return ;
}
void get_cent(Node &p)
{
    double temp = n ;
    double t = temp - (double) ( num2 - num1 ) * 2.0;
    double temp_deg = pi * t / temp / 2.0;
    double len = 0.5 / cos ( temp_deg );
    rotated_point(v2,v1,p,len,temp_deg);
    return ;
}



double dis(const Node &a ,const Node &b)
{
    double tmp = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return tmp;
}

int main()
{
    scanf("%d%d%d",&n,&num1,&num2);
    scanf("%lf%lf%lf%lf",&v1.x,&v1.y,&v2.x,&v2.y);
    if ( num1 > num2 )
    {
        swap ( num1 , num2 );
        swap ( v1 , v2 );
    }
    Node cent;
    get_cent(cent);
    num1 -- ;
    num2 -- ;
    v[num1] = v1 ; 
    v[num2] = v2 ;
    double cent_deg;
    for (int i = 1 ; i < n ; i ++)
    {
        int t = ( i + num1 ) % n ;
        cent_deg = -2 * pi * i / n ;
        if ( t != num2 )
        {
            rotated_point(cent , v[num1] , v[t] , 1 , cent_deg);
        }
    }
    for (int i = 0 ; i < n ; i ++)
    {
        printf("%.6lf %.6lf\n",v[i].x,v[i].y);
    }
}
