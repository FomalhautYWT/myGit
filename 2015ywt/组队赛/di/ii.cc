#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define DEBUG 0
const double PI = acos(-1.0);
const double EPS = 1e-11;
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
    double distTo(const point &p) const{
        double dx = x - p.x , dy = y - p.y;
        return hypot(dx , dy);
    }

    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    void write()
    {
        printf("(%.4lf,%.4lf)\n",x,y);
    }
}po[5],poy[5] , now[5][5];
point change[5] ;
void prepare()
{
    change[1] = point(5,0);
    change[2] = point(-5,0);
    change[3] = point(0,5);
    change[4] = point(0,-5);
}
int main()
{
    int cas;
    scanf("%d",&cas);
    prepare();
    for (int _ = 1 ; _ <= cas ; _ ++)
    {

        double ans = -100;
        for (int i = 1 ; i <= 4 ; i ++){
            poy[i].read();
            //po[i].write();
        }
        for (double alp = 0 ; alp < PI/2 ; alp += 1.1*1e-5)
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
                    if ((pup.y < now[i][j].y))
                        pup = now[i][j];
                    if ((pdo.y > now[i][j].y))
                        pdo = now[i][j];
                    if ((ple.x > now[i][j].x))
                        ple = now[i][j];
                    if ((pri.x < now[i][j].x))
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
                int shang = 0 , xia = 0 , zuo = 0 , you = 0;
                for (int i = 1; i <= 4 ; i ++)
                {
                    if ((sign(po[i].distTo(pup) - 5.0)) == 0 )
                        shang ++;
                    if ((sign(po[i].distTo(pdo) - 5.0)) == 0 )
                        xia ++;
                    if ((sign(po[i].distTo(ple) - 5.0)) == 0 )
                        zuo ++;
                    if ((sign(po[i].distTo(pri) - 5.0)) == 0 )
                        you ++;
                    if (shang + xia + zuo + you != i)
                        flag = false;
                    if (DEBUG)
                {
                    cout << shang << xia << zuo << you << endl;
                }
                }

                if (DEBUG)
                {
                    cout << shang << xia << zuo << you << endl;
                }
                if (shang == 1 && xia == 1 && zuo == 1 && you == 1)
                {

                }
                else flag = false;

            }
            else flag = false;
            if (flag)
            {
                if (sign(pup.y - pdo.y - ans) == 1)
                    ans = pup.y - pdo.y;
            }
        }
        printf("Case %d: ",_);
        if (sign(ans + 100.0) == 0)
            puts("no solution");
        else printf("%.2f\n",ans);
    }
}
//1 0 0 2 1 5 5 4
