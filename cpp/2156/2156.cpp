#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #2156

int glass[10001];
int memo[10001][2]; //0 Æ÷µµÁÖ ¸ÔÀ½, 1 ¾È¸ÔÀ½

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> glass[i];
	}
	for (int i = 1; i <= n; i++) {
		memo[i][0] = max(memo[i - 1][1]+glass[i], memo[i - 1][0]);
		memo[i][1] = max(memo[i - 2][0], memo[i - 2][1])+glass[i];
	}
	cout << max(memo[n][0], memo[n][1]);
	return 0;
}