#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007

typedef long long ll;

int pool[9000010][4]; //0: me,1: left child,2:right sibling,3:eow
int pidx = 2;

ll fact[28];

void add(string& s) {
  int size = s.size();
  int here = 1;
  for (int i = 0; i < size; i++) {
    int c = s[i] - 'A' + 1;
    int child = pool[here][1];
    if (child == 0) {
      child = pool[here][1] = pidx++;
      pool[child][0] = c;
    } else if (pool[child][0] != c) {
      int sibling = pool[child][2];
      while (sibling != 0 && pool[sibling][0] != c) {
        child = pool[child][2];
        sibling = pool[child][2];
      }
      if (sibling == 0) {
        sibling = pool[child][2] = pidx++;
        pool[sibling][0] = c;
      }
      child = sibling;
    }
    here = child;
  }
  pool[here][3] = 1;
}

ll find(int here = 1) {
  ll cnt = 1;
  int count = pool[here][3];
  int temp = pool[here][1];
  while (temp) {
    cnt = (cnt % MOD * find(temp) % MOD) % MOD;
    count++;
    temp = pool[temp][2];
  }
  cnt = (cnt % MOD * fact[count] % MOD) % MOD;
  return cnt % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s;
  fact[0] = 1;
  for (ll i = 1; i <= 27; i++) {
    fact[i] = (i % MOD * fact[i - 1] % MOD) % MOD;
  }
  while (n--) {
    cin >> s;
    add(s);
  }
  cout << find();
}