#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
char sta[200000];
char tar[200000];
int main()
{
    int cas;
    scanf("%d",&cas);
    while (cas--)
    {
      //  cout << cas << endl;
        //memset(sta,0,sizeof(sta));
        //memset(tar,0,sizeof(tar));
        scanf("%s",sta);
       // cout << sta <<endl;
        scanf("%s",tar);
       // cout << tar << endl;
        int stai = 0 , tari = 0;
        int stal = strlen(sta);
        int tarl = strlen(tar);
        bool yes = false;
        while(true)
        {
            if (stai == stal)
            {
                yes = true;
                break;
            }
            if (tari == tarl)
            {
                break;
            }
            if (sta[stai] == tar[tari])
            {
                stai++;
                tari++;
            }
            else{
                tari++;
            }
        }
        if (yes)
        {
            int yys = 1 , yyt = 1;
            for (int i = 1 ; i < stal ; i ++)
                if (sta[i] == sta[i - 1]) yys++;
            else break;
            for (int i = 1 ; i < tarl ; i ++)
                if (tar[i] == tar[i - 1]) yyt++;
            else break;
            if (yyt <= yys && sta[0] == tar[0])
            {
                printf("Yes\n");
                continue;
            }

        }
        printf("No\n");
    }
}
