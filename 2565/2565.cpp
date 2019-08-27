#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> arr[101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].second >> arr[i].first;
  }
  sort(arr, arr+n);
  vector<int> v;
  v.push_back(-987654321);
  for (int i = 0; i < n; i++) {
    if (v.back() < arr[i].second) {
      v.push_back(arr[i].second);
    } else {
      auto it = lower_bound(v.begin(), v.end(), arr[i].second);
      *it = arr[i].second;
    }
  }
  cout << n - (v.size()-1);
  return 0;
}