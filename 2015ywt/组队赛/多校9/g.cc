#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int a[200][200];
int f[200][200];
int main()
{
    int n , m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        int mina = ~0u >> 1;
        int sum = 0;
        int mini = 0 , minj = 0;
        for (int i = 1; i <= n ; i ++)
            for (int j = 1; j <= m ; j ++)
            {
                scanf("%d",&a[i][j]);
                sum += a[i][j];
                if ((i + j) & 1)
                {
                    if (a[i][j] < mina)
                    {
                        mina = a[i][j];
                        mini = i;
                        minj = j;
                    }
                }
            }

        if (n & 1)
        {
            printf("%d\n",sum);
            for (int i = 1; i < m ; i ++)
                printf("R");
            bool yes = true;
            for (int i = 1; i < n ; i ++)
            {
                printf("D");
                for (int j = 1; j < m ; j ++)
                {
                    if (yes)
                        printf("L");
                    else
                        printf("R");
                }
                yes = !yes;
            }
            puts("");
            continue;
        }
        if (m & 1)
        {
            printf("%d\n",sum);
            for (int i = 1; i < n ; i ++)
                printf("D");
            bool yes = true;
            for (int i = 1; i < m ; i ++)
            {
                printf("R");
                for (int j = 1; j < n ; j ++)
                {
                    if (yes)
                        printf("U");
                    else
                        printf("D");
                }
                yes = !yes;
            }
            puts("");
            continue;
        }
        printf("%d\n",sum - mina);
        if (mini & 1)
        {
            for (int i = 1; i <= n ; i ++)
            {
                for (int j = 1; j <= m ; j ++)
                {
                    if (i != mini && i != mini + 1)
                    {
                        if ((i & 1))
                        {
                            if (i < mini)
                                f[i][j] = 2;//ÓÒ
                            if (i > mini)
                                f[i][j] = 1;
                        }
                        else {
                            if (i < mini)
                                f[i][j] = 1;//×ó
                            if (i > mini)
                                f[i][j] = 2;
                        }
                    }
                }
            }
        }
        else{
            for (int i = 1; i <= n ; i ++)
            {
                for (int j = 1; j <= m ; j ++)
                {
                    if (i != mini && i != mini - 1)
                    {
                        if (i & 1)
                        {
                            if (i < mini)
                                f[i][j] = 2;
                            if (i > mini)
                                f[i][j] = 1;
                        }
                        else
                        {
                            if (i < mini)
                                f[i][j] = 1;
                            if (i > mini)
                                f[i][j] = 2;
                        }
                    }
                }
            }
        }
        int nowx = 1 , nowy = 1;
        while(true)
        {
            //system("pause");
            //cout <<"!"<< nowx << " "<< nowy << endl;
            if (nowx == n && nowy == m) break;
            if (f[nowx][nowy] == 2)
            {
                if (nowy != m)
                {
                    printf("R");
                    nowy ++;
                }

                else {
                    printf("D");
                    nowx ++;
                }
                continue;
            }
            if (f[nowx][nowy] == 1)
            {
                if (nowy != 1)
                {
                    printf("L");
                    nowy --;
                }
                else {
                    printf("D");
                    nowx ++;
                }
                continue;
            }
            if (f[nowx][nowy] == 0)
            {
                int tx = nowx + 1;
                int ty = m;
                if (minj == 1)
                {
                    printf("R");
                    nowy ++;
                }
                bool yes = true;
                while(true)
                {
                    //cout << nowx << " "<<nowy << endl;
                    //system("pause");
                    if (nowx == tx && nowy == ty)
                    {
                        if (nowx == n) break;
                        printf("D");
                        nowx++;
                        break;
                    }
                    if (yes)
                    {
                        nowx ++;
                        if (nowx == mini && nowy == minj)
                        {
                            printf("R");
                            nowx --;
                            nowy ++;
                            continue;
                        }
                        printf("D");
                    }
                    else{
                        nowx --;
                        if (nowx == mini && nowy == minj)
                        {
                            nowx ++;
                            nowy ++;
                            printf("R");
                            continue;
                        }
                        printf("U");
                    }
                    yes = !yes;
                    if(nowy == m) continue;

                    printf("R");
                    nowy ++;
                }
            }
        }
        puts("");
    }
}

/*
6 6
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 0 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
6 6
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 0 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
*/
