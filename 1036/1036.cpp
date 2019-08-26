#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;

typedef unsigned long long ull;

pair<string, int> cha[36];
string s[51];
bool convert[36];
int exist[36];

int convert10(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else {
    return c - 'A' + 10;
  }
}

char convert36(int n) {
  if (n < 10) {
    return n + '0';
  } else {
    return n - 10 + 'A';
  }
}

void add(string& dest, const string& src) {
  int carry = 0;
  int size = src.size();
  int dsize = dest.size();
  for (int i = size - 1, j = 0; ; i--, j++) {
    if (j >= dsize && i < 0) {
      break;
    }
    if (j < dsize && i >= 0) {
      int a = convert10(src[i]);
      int b = convert10(dest[j]);
      int c = a + b + carry;
      carry = c / 36;
      c %= 36;
      dest[j] = convert36(c);
    } else if (j >= dsize && i >= 0) {
      int a = convert10(src[i]) + carry;
      carry = a / 36;
      a %= 36;
      dest.push_back(convert36(a));
      dsize++;
    } else if (j < dsize && i < 0) {
      int b = convert10(dest[j]) + carry;
      carry = b / 36;
      b %= 36;
      dest[j] = convert36(b);
    }
  }
  if (carry) {
    dest.push_back(convert36(carry));
  }
}

void sub(string& dest, const string& src) {
  int size = dest.size();
  int carry = 0;
  for (int i = size - 1; i >= 0; i--) {
    int a = convert10(dest[i]);
    int b = convert10(src[i]);
    int c = a - b - carry;
    if (c < 0) {
      carry = 1;
      c += 36;
    }
    dest[i] = convert36(c);
  }
}

string check(string& s, int conv) {
  string a = s;
  for (int i = 0; i < a.size(); i++) {
    if (convert10(a[i]) == conv) {
      a[i] = 'Z';
    }
  }
  sub(a, s);
  return a;
}

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
  if (a.first.size() == b.first.size()) {
    for (int i = 0; i < a.first.size(); i++) {
      if (a.first[i] != b.first[i]) {
        return a.first[i] > b.first[i];
      }
    }
    return a.second < b.second;
  }
  return a.first.size() > b.first.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    int size = s[i].size();
    for (int j = 0; j < size; j++) {
      exist[convert10(s[i][j])] = i;
    }
    for (int j = 0; j < 36; j++) {
      if (exist[j] == i) {
        add(cha[j].first, check(s[i], j));
      }
    }
  }
  for (int i = 0; i < 36; i++) {
    while (cha[i].first.size() > 1 && cha[i].first.back() == '0') {
      cha[i].first.pop_back();
    }
    reverse(cha[i].first.begin(), cha[i].first.end());
    cha[i].second = i;
  }
  sort(cha, cha + 36, comp);
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    if (cha[i].second == 35) {
      k++;
    }
    convert[cha[i].second] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      if (convert[convert10(s[i][j])]) {
        s[i][j] = 'Z';
      }
    }
  }
  string ret;
  for (int i = 1; i <= n; i++) {
    add(ret, s[i]);
  }
  while (ret.size()>1 && ret.back() == '0') {
    ret.pop_back();
  }
  reverse(ret.begin(), ret.end());
  cout << ret;
  return 0;
}