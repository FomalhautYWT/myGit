#include <iostream>
using namespace std;

long long a[35][35];
long long b[35][35];
long long c[35][35];
int main() {
  int cas;
  std::cin >> cas;
  while (cas --) {
    long long k;
    std::cin >> k;
    std::cout << 30 << ' ' << 20 << "\n";
    for (int i = 0; i <= 30; i ++) {
      for (int j = 0; j <= 30; j ++) {
        a[i][j] = 0;
      }
    }
    for (int i = 1; i <= 10; i ++) {
      a[0][i] = 1;
      for (int j = 1; j <= 10; j ++) {
        a[i][j] = 1;
      }
    }
    for (int i = 11; i <= 28;  i++) {
      a[i][i + 1] = 1;
    }
    int cur = 11;
    while (k) {
      int m = k % 10;
      k /= 10;
      for (int i = 1; i <= m; i++) {
        a[i][cur] = 1;
      }
      cur ++;
    }
    for (int i = 0; i <= 29; i ++) {
      for (int j = 0; j <= 29; j ++)
        std::cout << a[i][j];
      std::cout << "\n";
    }
    /* Test
    for (int i = 0; i <= 29; i ++) {
      for (int j = 0; j <= 29; j ++) {
        c[i][j] = a[i][j];
      }
    }
    for (int p = 1; p <= 19;  p ++)  {
      memset(b, 0, sizeof(b));
      for (int i = 0; i <= 29; i ++) {
        for (int j = 0; j <= 29; j ++) {
          for (int k = 0; k <= 29; k ++) {
            b[i][j] += c[i][k] * a[k][j];
          }
        }
      }
      for (int i = 0; i <= 29; i ++) {
        for (int j = 0; j <= 29; j ++) {
          c[i][j] = b[i][j];
        }
      }
    }
    cout << c[0][29] << endl;
    */
  }
  return 0;
}
