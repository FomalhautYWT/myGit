#include<set>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>

using namespace std;
string spamStr;

const char cha[26][5] = {"4","|3","(","|)","3","|=","6","#","|","_|","|<","|_","|\\/|","|\\|","0","|0","(,)","|?","5","7","|_|","\\/","\\/\\/","><","-/","2"};
int dp[2000];

char str[1000];
set<string> chan;

int main()
{
    //cout << cha['M' - 'A'] << endl;
    for (int i = 0 ; i < 26 ; i ++)
        chan.insert(cha[i]);
    while (scanf("%s",str))
    {
        spamStr.clear();
        memset(dp,0,sizeof(dp));

        if (str[0]  == 'e')
            break;
        int len = strlen(str);
        for (int i = 0 ; i < len ; i ++)
        {
            spamStr += cha[str[i] - 'A'];
        }
        len = spamStr.length();
        //cout << spamStr <<endl;
        dp[0] = 1;
        for (int i = 0 ; i <= len ; i ++)
            for (int j = max( i - 10 ,  0  ) ; j <= i ; j ++)
            {

                if (chan.find(spamStr.substr(j,i - j)) != chan.end())
                {
                    //cout << spamStr.substr(j,i - j) << endl;
                    dp[i] += dp[j];
                    //cout <<i <<  " " << dp[i] <<" " <<  j <<  " " << dp[j] << endl;
                }

            }
        printf("%d\n",dp[len]);

    }
}
