#include <iostream>
using namespace std;
//BOJ #10818
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int max = -987654321;
	int min = 987654321;
	cin >> n;
	int j;
	for (int i = 0; i < n; i++) {
		cin >> j;
		if (j > max) {
			max = j;
		}
		if (j < min) {
			min = j;
		}
	}
	cout << min << ' ' << max;
	return 0;
}