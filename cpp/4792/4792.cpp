#include <iostream>
#include <queue>
using namespace std;

int parent[10001];

int find(int here) {
  if (here == parent[here]) {
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

void init(int n) {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
}

priority_queue<pair<int, pair<int, int>>> min_blue;
priority_queue<pair<int, pair<int, int>>> max_blue;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 0 && m == 0 && k == 0) {
      break;
    }
    char c;
    int f, t;
    for (int i = 0; i < m; i++) {
      cin >> c >> f >> t;
      if (f > t) {
        swap(f, t);
      }
      if (c == 'B') {
        min_blue.push({ -1,{f,t} });
        max_blue.push({ 1,{f,t} });
      } else {
        min_blue.push({ 0,{f,t} });
        max_blue.push({ 0,{f,t} });
      }
    }
    init(n);
    int min_k = 0;
    while (!min_blue.empty()) {
      auto p = min_blue.top();
      min_blue.pop();
      if (merge(p.second.first, p.second.second)) {
        min_k -= p.first;
      }
    }
    int max_k = 0;
    init(n);
    while (!max_blue.empty()) {
      auto p = max_blue.top();
      max_blue.pop();
      if (merge(p.second.first, p.second.second)) {
        max_k += p.first;
      }
    }
    cout << (min_k <= k && k <= max_k) << "\n";
  }
}