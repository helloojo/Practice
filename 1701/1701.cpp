#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int fail[5001];

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
  string s;
  cin >> s;
  int ret = 0;
  for (int i = 0; i < s.size(); i++) {
    memset(fail, 0, sizeof(fail));
    failure(s.substr(i));
    for (int j = 0; j < s.size() - i; j++) {
      ret = max(ret, fail[j]);
    }
  }
  cout << ret;
}