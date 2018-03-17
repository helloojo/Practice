#include <iostream>
using namespace std;
//BOJ #2525
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	b += c;
	a += b / 60;
	b %= 60;
	if (a >= 24) {
		a %= 24;
	}
	cout << a << ' ' << b;
	return 0;
}