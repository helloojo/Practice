#include <iostream>
using namespace std;
//BOJ #2455
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	int cur = 0;
	int max = -1;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		cur += b;
		cur -= a;
		if (cur > max) {
			max = cur;
		}
	}
	cout << max;
	return 0;
}