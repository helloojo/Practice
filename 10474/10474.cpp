#include <iostream>
using namespace std;
//BOJ #10474
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	while (!(a == 0 && b == 0)) {
		cout << a / b << ' ' << a % b << " / " << b << '\n';
		cin >> a >> b;
	}
	return 0;
}