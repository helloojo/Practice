#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> things[101];
int memo[101][100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> things[i].first >> things[i].second;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (things[i].first <= j) {
        memo[i][j] = max(memo[i - 1][j], things[i].second + memo[i - 1][j - things[i].first]);
      } else {
        memo[i][j] = memo[i - 1][j];
      }
    }
  }
  cout << memo[n][k];

  return 0;
}