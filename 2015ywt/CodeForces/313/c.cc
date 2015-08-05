#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int a1 , a2 , a3 , a5 , d;
    cin >> a1 >> a2 >> a3 >> a5 >> a5;
    d = a1 + a2 + a3;
    cout << d * d - ( a1 * a1 + a3 * a3 + a5 * a5 ) << endl;
}
