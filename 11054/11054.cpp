#include <iostream>
#include <algorithm>
using namespace std;
int memo[1001];
int memo2[1001];
int arr[1001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    int maxn = 0;
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        maxn = max(maxn, memo[j]);
      }
    }
    memo[i] = maxn + 1;
  }
  for (int i = n-1; i >=0; i--) {
    int maxn = 0;
    for (int j = n-1; j > i; j--) {
      if (arr[i] > arr[j]) {
        maxn = max(maxn, memo2[j]);
      }
    }
    memo2[i] = maxn + 1;
  }
  int maxn = 0;
  for (int i = 0; i < n; i++) {
    maxn = max(maxn, memo[i] + memo2[i]);
  }
  cout << maxn - 1;
  return 0;
}