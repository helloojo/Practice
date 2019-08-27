#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int size = s.size();
  int ret = 0;
  bool minus = false;
  int num = 0;
  for (int i = 0; i < size; i++) {
    switch (s[i]) {
    case '+':
      ret += (minus ? -num : num);
      num = 0;
      break;
    case '-':
      ret += (minus ? -num : num);
      num = 0;
      minus = true;
      break;
    default:
      num = num * 10 + (s[i] - '0');
      break;
    }
  }
  ret += (minus ? -num : num);
  cout << ret;
  return 0;
}