#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #2512
int money[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int high = 0;
	int low = 0;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		high = max(high, money[i] + 1);
	}
	int m;
	cin >> m;
	low = m / n - 1;
	int mid = (low + high) / 2;
	while (low + 1 < high) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (money[i] >= mid) {
				sum += mid;
			} else {
				sum += money[i];
			}
		}
		if (sum > m) {
			high = mid;
		} else {
			low = mid;
		}
		mid = (low + high) / 2;
	}
	cout << mid;
}