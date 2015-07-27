#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[9999];
int main()
{
    int cas;
    scanf("%d",&cas);
    getchar();
    for (int _ = 1; _ <= cas ; _ ++)
    {
        int ans = 0;
        scanf("%s",str);
        int len = strlen(str);
        for(int i = 0 ; i < len ; i ++)
        {
            ans += str[i] - '0';
        }
        scanf("%s",str);
        len = strlen(str);
        for(int i = 0 ; i < len ; i ++)
        {
            ans += str[i] - '0';
        }
        printf("Case %d: %d\n",_,ans);
    }
}
