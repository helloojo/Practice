#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int fail[1000001];

void failure(const string& pattern) {
  int size = pattern.size();
  int j = 0;
  for (int i = 1; i < size; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = fail[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      fail[i] = ++j;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (true) {
    memset(fail, 0, sizeof(fail));
    string s;
    cin >> s;
    if (s == ".") {
      break;
    }
    failure(s);
    int size = s.size();
    int ret = 1;
    if (fail[size - 1]) {
      if (size % (size - fail[size - 1])) {
        ret = 1;
      } else {
        ret = size / (size - fail[size - 1]);
      }
    }
    cout << ret << '\n';
  }
}