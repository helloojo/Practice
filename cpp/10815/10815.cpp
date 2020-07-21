#include <iostream>
using namespace std;
//BOJ #10815
typedef unsigned long long ull;
ull bit[320000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int num;
	while (n--) {
		cin >> num;
		num += 10000000;
		bit[num / 64] |= (1ull << (num%64));
	}
	int m;
	cin >> m;
	while (m--) {
		cin >> num;
		num += 10000000;
		if (bit[num / 64] & (1ull << (num % 64))) {
			cout << "1 ";
		} else {
			cout << "0 ";
		}
	}
}