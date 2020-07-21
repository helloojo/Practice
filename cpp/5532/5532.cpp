#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #5532
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	cout << l - max(a%c ? a/c+1:a/c, b%d?b/d+1:b/d);
	return 0;
}