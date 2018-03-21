#include <iostream>
using namespace std;
//BOJ #11060
int num[1001];
int memo[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		memo[i] = 987654321;
	}
	memo[0] = 0;
	for (int i = 1; i <= n; i++) {

	}
	return 0;
}