#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

typedef set<pair<int, int> >::iterator it;
typedef set<pair<int, int> >::reverse_iterator rit;
int T, n, k;
long long ans;
set<pair<int, int> > s;
int main()
{
    //
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &k);
        ans = 0; s.clear();
        int head = 1, x;
        for (int i = 1; i <= n; i++){
            scanf("%d", &x);
            for (it it0 = s.begin(); it0 != s.end();){
                it tmp;
                tmp = ++it0;
                it0--;
                if (abs(x - it0->first) < k) break;
                else{
                    head = max(head, it0->second+1);
                    s.erase(*it0);
                }
                it0 = tmp;
            }
            //puts("!");
            for (rit it0 = s.rbegin(); it0 != s.rend();){

                rit tmp;
                tmp = it0++;
               //     cout << it0->first << " it0+ " << it0->second << endl;
//puts("jg");
                it0--;
 //puts("##");
                if (abs(it0->first - x) < k) break;
                else{
                    head = max(head, it0->second+1);
                    //cout << it0->first << " it0- " << it0->second << endl;
                    s.erase(*it0);

                }
                it0 = tmp;

            }
            s.insert(make_pair(x, i));
            ans += i - head + 1;
           // puts("~");
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
