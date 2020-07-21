#include <iostream>
#include <cstring>
using namespace std;

bool h[720000];
bool f[360000];
int fail[360000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    h[num] = h[num + 360000] = 1;
  }
  for (int i = 0; i < n; i++) {
    cin >> num;
    f[num] = 1;
  }

  fail[0] = 0;
  int i = 1;
  int j = 0;
  while (i < 360000) {
    if (f[i] == f[j]) {
      fail[i++] = ++j;
    } else if (j > 0) {
      j = fail[j - 1];
    } else {
      fail[i++] = 0;
    }
  }

  i = j = 0;
  bool find = false;
  while (i < 720000) {
    if (h[i] == f[j]) {
      if (j == 360000 - 1) {
        find = true;
        break;
      } else {
        i++;
        j++;
      }
    } else {
      if (j > 0) {
        j = fail[j - 1];
      } else {
        i++;
      }
    }
  }
  cout << (find ? "possible" : "impossible");
}