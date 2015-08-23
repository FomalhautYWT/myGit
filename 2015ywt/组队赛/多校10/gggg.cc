#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

inline int Scan()     //ÊäÈëÍâ¹Ò
{
    int res=0,ch,flag=0;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        res=ch-'0';
    while((ch=getchar())>='0'&&ch<='9')
        res=res*10+ch-'0';
    return flag?-res:res;
}
const int N=100004, LEN=400, INF=~0u >> 1;

struct Block_List {
    struct Node {
        int buff[LEN], Size;
        void init() {
            memset(buff, 0, sizeof buff);
            Size=0;
        }
    } List[LEN];
    int tot;

    void init(int n, int A[]) {
        List[0].init(), tot=1;
        for(int i=0, cur=0; i<n; ) {
            for(int j=0; i<n && j<LEN; j++, i++) {
                List[cur].buff[j]=A[i];
                List[cur].Size++;
            }
            if(i==n) continue;
            List[tot++].init();
            cur++;
        }
        for(int i=0; i<tot; i++) sort(List[i].buff, List[i].buff+List[i].Size);
    }

    void update(int id, int old, int val) {
        for(int i=0; i<List[id].Size; i++) if(List[id].buff[i]==old) {
            List[id].buff[i]=val;
            break;
        }
        sort(List[id].buff, List[id].buff+List[id].Size);
    }

    int query(int id, int val) {
        int L=0, R=List[id].Size-1;
        while(L<R) {
            int mid=(L+R)>>1;
            if(List[id].buff[mid]>val) R=mid;
            else L=mid+1;
        }
        if(List[id].buff[L]>val) L--;
        return L+1;
    }

    void NewNode(int id, int A[], int L, int R) {
        List[id].init();
        for(int i=L; i<=R; i++) List[id].buff[i-L]=A[i];
        List[id].Size=R-L+1;
        sort(List[id].buff, List[id].buff+List[id].Size);
    }
};

int A[N], n, m, t;
Block_List hehe;
int cmd;
vector <int> tub;

int main() {
    freopen("1007.in", "r", stdin);
    freopen("1007.out","w",stdout);

    while(scanf("%d",&n)!=EOF){
        for(int i=0; i<n; i++)
            A[i] = Scan();
            //scanf("%d", &A[i]);
        hehe.init(n, A);
        m = Scan();//scanf("%d",&m);
        for(int i=0, a, b, c; i<m; i++) {
            cmd = Scan();
            //scanf("%d",&cmd);
            if(cmd==2) {
                a = Scan();
                b = Scan();
                c = Scan();
                //scanf("%d%d%d", &a, &b, &c);
                a--, b--;
                int id1=a/LEN, id2=b/LEN;
                tub.clear();
                if(id1==id2) {
                    hehe.NewNode(hehe.tot, A, a, b);
                    tub.push_back(hehe.tot);
                }
                else {
                    hehe.NewNode(hehe.tot, A, a, (id1+1)*LEN-1);
                    hehe.NewNode(hehe.tot+1, A, id2*LEN, b);
                    tub.push_back(hehe.tot);
                    tub.push_back(hehe.tot+1);
                    for(int i=id1+1; i<id2; i++) tub.push_back(i);
                }
                int L=0, R=INF;
                while(L<R) {
                    int mid=(L+R)>>1;
                    int sum=0;
                    for(int i=0, len=(int)tub.size(); i<len; i++) {
                        sum+=hehe.query(tub[i], mid);
                    }
                    if(sum<c) L=mid+1;
                    else R=mid;
                }
                printf("%d\n", L);
            }
            else {
                a = Scan();
                b = Scan();
                //scanf("%d%d", &a, &b);
                a--;
                hehe.update(a/LEN, A[a], b);
                A[a]=b;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
}

