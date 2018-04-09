#include <iostream>
#include <cstring>
using namespace std;
//BOJ #9095
int memo[12];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(Nint);
	int t;
	cin >> t;
	int n;
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 3;
	for (int i = 4; i <= 11; i++) {
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3]+3;
	}
	while (t--) {
		cin >> n;
		cout << memo[n] << '\n';
	}
	return 0;
}