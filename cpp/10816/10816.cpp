#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cin >> m;
  int num;
  for (int i = 0; i < m; i++) {
    cin >> num;
    cout << upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num) << ' ';
  }
}