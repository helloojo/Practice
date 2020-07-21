#include <iostream>
using namespace std;

int memo[10001];
int coin[21];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    memo[0] = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> coin[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < n; i++) {
      for (int j = coin[i]; j <= m; j++) {
        memo[j] += memo[j - coin[i]];
      }
    }
    cout << memo[m] << '\n';
    for (int i = 1; i <= m; i++) {
      memo[i] = 0;
    }
  }
}