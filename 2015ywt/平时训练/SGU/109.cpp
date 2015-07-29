#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n;
int calc(int i ,int j)
{
    return (i - 1) * n + j;
}

int main()
{
    scanf("%d",&n);
    if ( n == 2 )
    {
        cout << 2 << " " << 2 << endl;
        cout << 3 << " " << 1 << " " << 4 << endl;
        return 0;
    }
    printf("%d",n);
    for (int i = 3 ; i <= n;i ++)
    {
        for (int j = n - i + 3 ; j <= n ; j ++)
        {
            printf(" %d",calc(i,j));
        }
    }
    printf("\n");
    int k = n | 1;
    if ( n & 1 ) k += 2;
    printf("%d",k);
    k += 2;
    int x = 2 , y = n;
    printf(" %d",calc(x,y));
    while( x < n )
    {
        x++ ; 
        y-- ;
        printf(" %d",calc(x,y));
    }
    printf("\n");
    for (int i =n; i >= 2;i--)
    {
        printf("%d",k);
        k += 2;
        int x = 1, y = i;
        printf(" %d",calc(x,y));
        while ( y > 1 )
        {
            x++;y--;
            printf(" %d",calc(x,y));
        }
        printf("\n");
    }


}
