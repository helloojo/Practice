#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//BOJ #14864
int arr[100001];
bool check[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a]++;
		arr[b]--;
	}
	bool can = true;
	for (int i = 1; i <= n; i++) {
		if (arr[i]<0 || arr[i]>n || check[arr[i]]) {
			can = false;
			break;
		}
		check[arr[i]] = true;
	}
	if (can) {
		for (int i = 1; i <= n; i++) {
			cout << arr[i]<<' ';
		}
	} else {
		cout << -1 << '\n';
	}
}