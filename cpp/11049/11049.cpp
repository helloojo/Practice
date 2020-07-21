#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> matrix[501];

int memo[501][501];

int calc(int src, int dest) {
  if (src == dest) {
    return 0;
  }
  if (memo[src][dest]) {
    return memo[src][dest];
  }
  int minval = 2147483647;
  for (int k = src; k < dest; k++) {
    minval = min(minval, calc(src, k) + calc(k + 1, dest) + matrix[src].first * matrix[k].second * matrix[dest].second);
  }
  return memo[src][dest] = minval;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> matrix[i].first >> matrix[i].second;
  }
  cout << calc(0, n - 1);
  return 0;
}