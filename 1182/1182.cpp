#include <iostream>
using namespace std;
//BOJ #1182
int n, s;
int arr[21];

int solve(int pos, int sum) {
	int ret = 0;
	if (sum == s) {
		ret++;
	}
	for (int i = pos+1; i < n; i++) {
		ret += solve(i, sum + arr[i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += solve(i, arr[i]);
	}
	cout << ret;
}