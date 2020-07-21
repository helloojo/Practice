#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

vector<pair<string, string>> v;

int main() {
  string s;
  getline(cin, s);
  int size = s.size();
  string base;
  bool isbase = true;
  bool isvar = false;
  int varidx = 0;
  bool isvartype = false;
  for (int i = 0; i < size; i++) {
    if (s[i] == ';') {
      reverse(v[varidx].second.begin(), v[varidx].second.end());
      continue;
    }
    if (s[i] == ' ' && isbase) {
      isbase = false;
      isvar = true;
      v.push_back({ "","" });
      continue;
    } else if (s[i] == ' ') {
      continue;
    }
    if (s[i] == ',' && isvar) {
      isvartype = false;
      v.push_back({ "","" });
      reverse(v[varidx].second.begin(), v[varidx].second.end());
      varidx++;
      continue;
    }
    if (isbase) {
      base.push_back(s[i]);
    } else if (isvar) {
      if (!isalpha(s[i])) {
        isvartype = true;
      }
      if (isvartype) {
        if (s[i] == '[') {
          v[varidx].second.push_back(']');
          v[varidx].second.push_back('[');
          i++;
        } else {
          v[varidx].second.push_back(s[i]);
        }
      } else {
        v[varidx].first.push_back(s[i]);
      }
    }
  }
  for (int i = 0; i < v.size(); i++) {
    cout << base << v[i].second << ' ' << v[i].first << ";\n";
  }
  return 0;
}