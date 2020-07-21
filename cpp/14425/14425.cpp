#include <iostream>
#include <string>
using namespace std;

int pool[5000000][26];
bool eow[5000000];
int pcnt = 1;
void add(string& s) {
  int size = s.size();
  int here = 0;
  for (int i = 0; i < size; i++) {
    if (pool[here][s[i] - 'a'] == 0) {
      pool[here][s[i] - 'a'] = pcnt++;
    }
    here = pool[here][s[i] - 'a'];
  }
  eow[here] = true;
}

bool find(string& s) {
  int size = s.size();
  int here = 0;
  for (int i = 0; i < size; i++) {
    if (pool[here][s[i] - 'a'] == 0) {
      return false;
    }
    here = pool[here][s[i] - 'a'];
  }
  return eow[here];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  string s;
  while (n--) {
    cin >> s;
    add(s);
  }
  int ret = 0;
  while (m--) {
    cin >> s;
    ret = (find(s) ? ret + 1 : ret);
  }
  cout << ret;
}