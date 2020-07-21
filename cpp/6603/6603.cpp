#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//BOJ #6603

int arr[13];
int lotto[6];
void print() {
  for (int i = 0; i < 6; i++) {
    cout << lotto[i] << ' ';
  }
  cout << '\n';
}
void find(int here,int k, int idx=1) {
  if (idx == 6) {
    print();
    return;
  }
  for (int i = here + 1; i < k; i++) {
    lotto[idx] = arr[i];
    find(i, k, idx + 1);
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cout.tie(NULL);
  int k;
  while (true) {
    cin >> k;
    if (k == 0) {
      break;
    }
    for (int i = 0; i < k; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
      lotto[0] = arr[i];
      find(i, k);
    }
    cout << '\n';
  }
	return 0;
}