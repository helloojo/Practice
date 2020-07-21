#include <iostream>
using namespace std;
//BOJ #13306
int num[200001];
int memo[200001];


int find(int x) {
	if (num[x] == x) {
		return x;
	}
	if (memo[x]) {
		return memo[x];
	}
	return memo[x]=find(num[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	num[1] = 1;
	for (int i = 1; i < n; i++) {
		cin >> num[i + 1];
	}
	int x, a, b;
	for (int i = 0; i < n + q - 1; i++) {
		cin >> x >> a;
		switch (x) {
		case 0:
			num[a] = a;
			memo[a] = a;
			break;
		case 1:
			cin >> b;
			if (find(a) == find(b)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
			break;
		}
	}
	return 0;
}