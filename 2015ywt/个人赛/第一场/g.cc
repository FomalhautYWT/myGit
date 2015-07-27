#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int primeNum[4000 + 99];
int pNum = 0 , n;
char str[10000];
int zhNum[100];
bool pr[4000 + 99];
int ans = 0 , ll;
int num[100] , len;
set < int > have;
void prime()
{
    for (int i = 2 ; i < 4000 ; i ++)
    {
        if ( ! pr[i] ) primeNum[pNum ++] = i;
        for (int j = 0 ; (j < pNum) && (primeNum[j] * i < 4000) ; j ++)
        {
            pr[primeNum[j] * i] = 1;
            if ( i % primeNum[j] == 0) break;
        }
    }
}
bool isPrime(int p)
{
    if ( p < 2) return 0;
    for (int i = 0 ; primeNum[i] * primeNum[i] <= p ; i ++)
    {
        if (p % primeNum[i] == 0) return 0;
    }
    return 1;
}
void calcZH(int p)
{
    ll = 0;
    //cout <<"p " <<p << endl;
    //cout << len << endl;
    for (int i = 0; i < len ; i ++)
    {
        if ( (p & ( 1 << i)) > 0 )
            zhNum[ll ++] = num[i];
    }
    //cout << ll << endl;
    //cout << "zuheNum ";
    /*for (int i = 0 ; i < ll ; i ++)
    {
        cout << zhNum[i] <<" " ;
    }
    cout << endl;*/
}

void calcAns()
{
    do
    {
        int now = 0;
        for (int i = 0 ; i < ll ; i ++) now = now * 10 + zhNum[i];
        if (have.find(now) != have.end()) continue;
        if (isPrime(now))
        {
            have.insert(now);
            ans ++;
        }
    }while ( next_permutation(zhNum,zhNum+ll));
}
int main()
{
    prime();
    scanf("%d",&n);
    for (int i = 1; i <= n ; i ++)
    {
        ans = 0;
        have.clear();
        scanf("%s",str);
        len = strlen(str);
        for (int j = 0 ; j < len ; j ++)
        {
            num[j] = str[j] - '0';
        }
        sort(num,num+len);
        //for (int j = 0 ; j < len ; j ++)
        //    cout << num [j] << " ";
        //cout << endl;
        for (int i = 1; i <= (1 << len) - 1 ; i ++)
        {
            calcZH(i);
            calcAns();
        }
        printf("%d\n",ans);

    }
}
