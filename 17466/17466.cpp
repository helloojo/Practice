#include <iostream>

using namespace std;

int main() {
  int n, p;
  cin >> n >> p;
  long long ret=1;
  for (int i = 1; i <= n; i++) {
    ret = (ret % p * i % p) % p;
  }
  cout << ret;
}