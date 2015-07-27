#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
long long CC[20][20];
long long SS[20][20];
long long fo[20];
void C()
{
    CC[0][0] = 1;
    for (int i = 1 ; i <= 12 ; i ++)
        for (int j = 0 ; j <= i ; j ++)
        CC[i][j] = CC[i - 1][j] + CC[i-1][j-1];
    /*for (int i = 0 ; i <= 12 ; i ++)
    {


        for (int j = 0 ; j <= 12 ; j ++)
            cout << CC[i][j] << " ";
        cout << endl;
    }*/

}
void S()
{
    for (int i = 0 ; i <= 12 ; i ++)
        for (int j = 0 ; j <= i ; j ++)
        if (i == j) SS[i][j] = 1;
        else if (j == 0) SS[i][j] = 0;
        else SS[i][j] = j * SS[i - 1][j] + SS[i - 1][j - 1];
    /*for (int i = 0 ; i <= 12 ; i ++)
    {
        for (int j = 0 ; j <= 12 ; j ++)
            cout << SS[i][j] << " " ;
        cout << endl;
    }*/
}
void FO()
{
    fo[0] = 1;
    for (long long i = 1 ; i <= 12 ; i ++)
        fo[i] = i * fo[i - 1];
    /*for (int i = 0; i <= 12 ; i ++)
        cout << "FO " << fo[i] << endl;*/
}
void prepare()
{
    C();    S();    FO();
}
int main()
{
    int cas;
    scanf("%d",&cas);
    prepare();
    for (int _ = 1 ; _ <= cas ; _ ++)
    {
        int p;
        scanf("%d",&p);
        long long ans = 0;
        for (int i = 1; i <= p ; i ++)
        {

            for (int j = 1 ; j <= i ; j ++)
            {
                ans += CC[p][i] * SS[i][j] * fo[j];
                //cout << CC[p][i] << " " << SS[i][j] << " "<< fo[j] << endl;

            }
        }
        printf("%d %d %lld\n",_,p,ans);
    }
}
