#include <iostream>
using namespace std;
//BOJ #5032
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e, f, c;
	cin >> e >> f >> c;
	int cur = e + f;
	int ret = 0;
	while (cur >= c) {
		ret += cur / c;
		cur = cur % c + cur / c;
	}
	cout << ret;
	return 0;
}