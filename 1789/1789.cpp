#include <iostream>
using namespace std;
//BOJ #1789
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ull s;
	cin >> s;
	ull i = 1;
	while (i*i + i <= 2 * s) {
		i++;
	}
	cout << i - 1;
	return 0;
}