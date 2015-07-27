#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct matrix
{
    double ma[2][2];
    matrix ()
    {
        memset(ma,0,sizeof(ma));
    }
    void print()
    {
        cout << ma[0][0] << " " << ma[0][1] << endl;
        cout << ma[1][0] << " " << ma[1][1] << endl;
    }
};
matrix mult( matrix a , matrix b)
{
    matrix ans;
    for (int n = 0 ; n < 2 ; n ++)
        for (int m = 0 ; m < 2 ; m ++)
            for (int p = 0 ; p < 2 ; p ++)
                ans.ma[n][p] += a.ma[n][m] * b.ma[m][p];

    return ans;
}
matrix pow(matrix a , int po)
{
    matrix ans;
    for (int i = 0 ; i < 2 ; i ++) ans.ma[i][i] = 1;
    matrix temp = a;
    while (po)
    {
        if (po & 1)
            ans = mult(ans , temp);
        temp = mult(temp , temp);
        po >>= 1;
    }
    return ans;
}

double dp(matrix te, int x )
{
    if (x == 0) return 1;
    matrix ans = pow(te , x - 1);
    //ans.print();
    //te.print();
    //cout << x << " " <<ans.ma[0][0] << endl;
    return (1 - ans.ma[0][0]);
}
int n ;
double p;
int bow[500];
int main()
{

    while (scanf("%d%lf",&n , &p) !=EOF)
    {
        for (int i = 1; i <= n ; i ++)
            scanf("%d",&bow[i]);
        sort(bow + 1 , bow + n + 1);
        double ans = 1.0;
        matrix te;
        te.ma[0][0] = p;
        te.ma[0][1] = 1 - p;
        te.ma[1][0] = 1;
        for (int i = 1 ; i <= n ; i ++)
        {
            ans *= dp(te , bow[i] - bow[i - 1]);

        }

        printf("%.7f\n",ans);
    }

}
