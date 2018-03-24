#include <iostream>
using namespace std;
//BOJ #10871
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (cur < x) {
			cout << cur << ' ';
		}
	}
	return 0;
}