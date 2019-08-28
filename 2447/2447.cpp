#include <iostream>
using namespace std;

void solve(int i, int j, int n) {
  if (n == 3) {
    int num = i * 3 + j;
    switch (num) {
    case 4:
      cout << ' ';
      break;
    default:
      cout << '*';
      break;
    }
    return;
  } else {
    int num = (i / (n / 3)) * 3 + (j / (n / 3));
    if (num == 4) {
      cout << ' ';
    } else {
      solve(i % (n / 3), j % (n / 3), n / 3);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      solve(i, j, n);
    }
    cout << '\n';
  }
}