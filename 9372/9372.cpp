#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int parent[1001];

void init(int n) {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
}

int find(int here) {
  if (parent[here] == here) {
    return here;
  }
  return parent[here] = find(parent[here]);
}

bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    return false;
  }
  parent[u] = v;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    init(n);
    int ret = 0;
    int a, b;
    while (m--) {
      cin >> a >> b;
      if (a > b) {
        swap(a, b);
      }
      if (merge(a, b)) {
        ret++;
      }
    }
    cout << ret << '\n';
  }
}