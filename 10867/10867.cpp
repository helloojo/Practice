#include <iostream>
using namespace std;
//BOJ #10867

bool num[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		num[a + 1000] = true;
	}
	for (int i = 0; i <= 2000; i++) {
		if (num[i]) {
			cout << i - 1000 << ' ';
		}
	}
	return 0;
}