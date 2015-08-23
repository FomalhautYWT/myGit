#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define DEBUG 0
const double PI = acos(-1.0);
const double EPS = 1e-8;
inline int sign(double a)
{
    return a < -EPS ? -1 : a > EPS;
}
struct point{
    double x ,y ;
    point(){};
    point(double _x , double _y):x(_x),y(_y){
    }
    point operator + ( const point & p) const{
        return point(x + p.x , y + p.y);
    }
    point rotAlpha(const double &alpha, const point & o = point(0,0)) const {

        double nx = cos(alpha) * ( x - o.x ) + sin(alpha) * ( y - o.y );
        double ny = -sin(alpha) * ( x - o.x ) + cos(alpha) * ( y - o.y );
        return point(nx,ny) + o;
    }
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    void write()
    {
        printf("(%.4lf,%.4lf)\n",x,y);
    }
}po[5] , now[5][5],poy[5];
point change[5] ;
void prepare()
{
    change[1] = point(5,0);
    change[2] = point(-5,0);
    change[3] = point(0,5);
    change[4] = point(0,-5);
}
double check(double alp)
{
    for (int i = 1; i <= 4 ; i ++)
    {
        po[i] = poy[i].rotAlpha(alp);
        //po[i].write();
    }
    point pup(0,-2000), pdo(0,2000) , ple(2000,0),pri(-2000,0);
    for (int i = 1 ; i <= 4; i ++)
    {
        for (int j = 1; j <= 4 ; j ++)
        {
            now[i][j] = po[i] + change[j];
            if (pup.y < now[i][j].y)
                pup = now[i][j];
            if (pdo.y > now[i][j].y)
                pdo = now[i][j];
            if (ple.x > now[i][j].x)
                ple = now[i][j];
            if (pri.x < now[i][j].x)
                pri = now[i][j];
        }
    }

    if (DEBUG)
    {
        pup.write();
        pdo.write();
        ple.write();
        pri.write();
        system("pause");
    }

    bool flag = true;
    if (sign(pup.y - pdo.y - pri.x + ple.x) == 0)
    {
        for (int i = 1; i <= 4 ; i ++)
            for (int j = i + 1 ; j <= 4 ; j ++)
            {

                if (sign(po[i].x - po[j].x) == 0)
                    flag = false;
                if (sign(po[i].y - po[j].y) == 0)
                    flag = false;
                if (DEBUG)
                {
                    if (flag == false)
                        cout << i << " " << j << endl;
                }
            }
    }
    else flag = false;
    if (flag)
    {
        return pup.y - pdo.y;
    }
    return -100;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    prepare();
    for (int _ = 1 ; _ <= cas ; _ ++)
    {
        double l , r;
        double ans = -100;
        for (int i = 1 ; i <= 4 ; i ++){
            poy[i].read();
            //po[i].write();
        }
        cout << check(PI/4) << endl;
        if (sign(check(PI / 4) + 100) == 0 && sign(check(PI / 5) + 100) == 0)
        {
            ans = -100;
        }else{
            l = 0 , r = PI / 2;
            for (int i = 1 ; i <= 10000 ; i ++)
            {
                double mid1 = (r - l) / 3.0 + l;
                double mid2 = (r - l) / 3.0 * 2.0 + l;
                double now1 = check(mid1);
                double now2 = check(mid2);
                if (sign(now1 - now2) == 1)
                    r = mid2;
                else if (sign(now1 - now2) == -1)
                    l = mid1;
                else l = mid1;
                cout << l << " " << r << endl;
                system("pause");
            }
        }


        printf("Case %d: ",_);
        if (sign(ans + 100.0) == 0)
            puts("no solution");
        else printf("%.2f\n",check(l));
    }
}
