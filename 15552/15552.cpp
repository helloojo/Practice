#include <iostream>
using namespace std;
//BOJ #
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int a, b;
	while (t--) {
		cin >> a >> b;
		cout << a + b<<'\n';
	}
	return 0;
}