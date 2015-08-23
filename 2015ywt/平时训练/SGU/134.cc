#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
    scanf("%d",&n);
    for (int i = 1 ; i < n ; i ++)
    {
        scanf("%d%d",&x,&y);
        add_edge(x , y);
    }


}
