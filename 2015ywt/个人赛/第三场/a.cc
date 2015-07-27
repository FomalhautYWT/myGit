#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char str[10000];
int main()
{
    while(true)
    {
        gets(str);
        if (str[0] == '#') break;
        int ans = 0;
        int len = strlen(str);
        for (int i = 0 ; i < len ; i ++)
        {
            if (str[i] != ' ')
            ans += ( i + 1 ) * (str[i] - 'A' + 1);
        }
        printf("%d\n",ans);
    }
}
