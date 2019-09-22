#include <iostream>
#include <algorithm>
using namespace std;

int home[200001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> home[i];
  }
  sort(home, home + n);
  int left = 1;
  int right = home[n - 1] - home[0];
  int ret;
  while(left<=right) {
    int mid = (left + right) / 2;
    int cnt = 1;
    int base = home[0];
    for (int i = 1; i < n; i++) {
      if (home[i] - base >= mid) {
        cnt++;
        base = home[i];
      }
    }
    if (cnt < c) {
      right = mid - 1;
    } else {
      left = mid + 1;
      ret = mid;
    }
  }
  cout << ret;
}