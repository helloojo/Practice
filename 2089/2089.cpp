#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << "0";
    return 0;
  }
  deque<char> ret;
  while (n) {
    int t = n % -2;
    n /= -2;
    if (t == -1) {
      n++;
      t = -t;
    }
    ret.push_back(t + '0');
  }
  for (int i = ret.size() - 1; i >= 0; i--) {
    cout << ret[i];
  }
  return 0;
}