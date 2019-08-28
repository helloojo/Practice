#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[21][21];
int team[21];
bool choose[21];
int n;
int ret = 987654321;

int cal() {
  int ret = 0;
  int idx = 0, idx2 = n / 2;
  for (int i = 0; i < n; i++) {
    if (choose[i]) {
      team[idx++] = i;
    } else {
      team[idx2++] = i;
    }
  }
  for (int i = 0; i < n / 2; i++) {
    for (int j = i + 1; j < n / 2; j++) {
      ret += arr[team[i]][team[j]];
      ret += arr[team[j]][team[i]];
    }
  }
  for (int i = n / 2; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ret -= arr[team[i]][team[j]];
      ret -= arr[team[j]][team[i]];
    }
  }
  return ret;
}

void solve(int here, int idx = 1) {
  if (idx == n / 2) {
    int c = abs(cal());
    ret = min(ret, c);
    return;
  }
  for (int i = here + 1; i < n; i++) {
    if (!choose[i]) {
      choose[i] = true;
      solve(i, idx + 1);
      choose[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    choose[i] = true;
    solve(i);
    choose[i] = false;
  }
  cout << ret;
}