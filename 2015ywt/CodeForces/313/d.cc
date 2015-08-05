#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
string str1 , str2 ;
string trans(string str)
{
    int len = str.length();
    if (len & 1)
        return str;
    string s1 = trans(str.substr(0,len/2));
    string s2 = trans(str.substr(len/2,len/2));

    if (s1 < s2)
        return s1 + s2;
    else
        return s2 + s1;
}
int main()
{
    cin >> str1 >> str2 ;
    if (trans(str1) == trans(str2))
    {
        puts("YES");
    }
    else puts("NO");
}
