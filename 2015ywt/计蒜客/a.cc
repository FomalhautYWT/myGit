#include<iostream>
#include<cstdio>
using namespace std;
const int Num[10] = {6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6};
const int Month[13] = {0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};

struct date{
    int y , d , m ;
    bool run(int p)
    {
        return (p % 400 == 0) || (p % 100 != 0 && p % 4 == 0);
    }
    date ()
    {

    }
    date (char * t)
    {
        //cout << t << endl;
        y = 0 , m = 0 , d = 0 ;
        for (int i = 0 ; i < 4 ; i ++)
        {
            y *= 10;
            y += t[i] - '0';

        }
        for (int i = 4 ; i < 6 ; i ++)
        {
            m *= 10;
            m += t[i] - '0';

        }
        for (int i = 6 ; i < 8 ; i ++)
        {
            d *= 10;
            d += t[i] - '0';

        }

    }
    void add()
    {
        //cout <<"!"<<endl;
        d ++;
        //cout <<"!"<<endl;
        if (d > Month[m])
        {
            if (m != 2) {
                d = 1 ;
                m ++;
                if (m > 12)
                {
                    m = 1;
                    y ++;
                }
            }
            else {
                if (run(y) && d == 30){
                    m ++ ;
                    d = 1;
                }
            }
        }
    }
    int getB()
    {
        int ans = 0;
        int now = y;
        while (now)
        {
            ans += Num[now % 10];
            now /= 10;
        }
        now = m;
        for (int i = 0 ; i <= 1 ; i ++)
        {
            ans += Num[now % 10];
            now /= 10;
        }
        now = d;
        for (int i = 0 ; i <= 1 ; i ++)
        {
            ans += Num[now % 10];
            now /= 10;
        }
        return ans;
    }
    void print()
    {
        cout << y << " "<< m << " "<< d  << endl;
    }

    bool lessThan(date l)
    {
        if (y < l.y) return 1;
        if (m < l.m) return 1;
        if (d < l.d) return 1;
        return 0;
    }
};
char str[20];
int pt;
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas --)
    {

        scanf("%s",&str);
        scanf("%d",&pt);
        bool flag = 0;
        date p(str);
        date ed("29991231");
        for (int i = 0 ; p.lessThan(ed);p.add(),i++)
        {
            if (p.getB() == pt && !flag){
                cout << i << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << -1 << endl;
        }
    }
}
