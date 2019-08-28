#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9];
int base[11];
bool used[9];
int n, k;
vector<long long> v;

void solve(int here, int n, long long l = 0, long long r = 0, int idx = 0) {
  if (l != 0 && r != 0 && l == r) {
    long long num = 0;
    for (int i = 0; i < 11; i++) {
      if (i == 5) continue;
      num = num * 10 + base[i];
    }
    v.push_back(num);
  }
  if (idx == n) {
    return;
  }
  for (int i = here; i < 11; i++) {
    if (i == 5) continue;
    else if (i > 5) {
      if (r + arr[0] * (i - 5) > l) {
        continue;
      }
    }
    if (base[i] == 0) {
      for (int j = 0; j < n; j++) {
        if (!used[j]) {
          long long left = l;
          long long right = r;
          if (i > 5) {
            right += (i - 5) * arr[j];
            if (right > left) {
              continue;
            }
          } else {
            left += (5 - i) * arr[j];
          }
          base[i] = arr[j];
          used[j] = true;
          solve(i + 1, n, left, right, idx + 1);
          base[i] = 0;
          used[j] = false;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> k;
  if (k == 0) {
    cout << 0;
  } else {
    solve(0, n);
    sort(v.begin(), v.end());
    if (k > v.size()) {
      cout << v.back();
    } else {
      cout << v[k - 1];
    }
  }
  return 0;
}