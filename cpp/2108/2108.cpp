#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//BOJ #2108

int num[8002];
int number[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int sum = 0;
	int maxn = -5000;
	int minn = 5000;
	int maxbin = 0;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
		sum += number[i];
		num[number[i] + 4000]++;
		if (num[number[i] + 4000] > num[maxbin]) {
			maxbin = number[i] + 4000;
		}
		if (number[i] > maxn) {
			maxn = number[i];
		}
		if (number[i] < minn) {
			minn = number[i];
		}
	}
	sort(number, number + n);
	int cnt = 0;
	for (int i = 0; i <= 8000; i++) {
		if (num[i] == num[maxbin]) {
			cnt++;
			maxbin = i;
		}
		if (cnt == 2) {
			maxbin = i;
			break;
		}
	}
	cout << floor((sum / (double)n) + 0.5) << '\n';
	cout << number[n / 2] << '\n';
	cout << maxbin - 4000 << '\n';
	cout << maxn - minn << '\n';
	return 0;
}