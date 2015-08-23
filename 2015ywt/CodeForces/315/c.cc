#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

#define DEBUG 0
long long pr[5000006];
long long pNum = 0;
long long primeNum[5000006];
long long prsum[5000006];
void prime()
{
    for (int i = 2 ; i < 5000000 ; i ++)
    {
        if ( ! pr[i] ) primeNum[pNum ++] = i;
        for (int j = 0 ; (j < pNum) && (primeNum[j] * i < 5000000) ; j ++)
        {
            pr[primeNum[j] * i] = 1;
            if ( i % primeNum[j] == 0) break;
        }
    }
    int yes = 0;
    for (int i =2 ; i <= 5000000 ; i ++)
    {
        prsum[i] = prsum[i - 1] + (1 - pr[i]);
    }
}
long long num[100000];
long long posum[5000006];
bool ispoll(int x)
{
    if (x < 10) return true;
    int len = 0;
    while(x)
    {
        len++;
        num[len] = x % 10;
        x /= 10;
    }
    int j = len;
    for (int i = 1; i <= len ; i ++ , j--)
    {
        if (num[i] != num[j]) return false;
    }
    return true;
}
void poll()
{
    for (int i = 1; i <= 5000000 ; i ++)
    {
        if (ispoll(i))
            posum[i] = posum[i - 1] + 1;
        else posum[i] = posum[i - 1];
    }
}
void prepare()
{
    prime();
    poll();
}
int main()
{
    prepare();
    long long p , q;
    scanf("%I64d%I64d",&p,&q);
    if (DEBUG) if (q * prsum[5000000] <= p * posum[5000000]){
        printf("Palindromic tree is better than splay tree\n");
        return 0;
    }
//cout <<ispoll(p) << endl;
    for (int i = 5000000 ; i >= 1 ; i --)
    {
        //cout <<i << " " << prsum[i] << " " << posum[i] << endl;
        //system("pause");

        if (q * prsum[i] <= p * posum[i])
        {
            //cout <<i << " " << prsum[i] << " " << posum[i] << endl;
            //system("pause");
            printf("%d\n",i);
            return 0;
        }
    }

}
