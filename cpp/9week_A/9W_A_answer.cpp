#include <iostream>
#include <algorithm>
using namespace std;

int bread[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int avg = m/n;
		int num = n;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			cin >> bread[i];
			if (avg >= bread[i]) {
				m -= bread[i];
				num--;
			}
		}
		avg = m / n;
		for (int i = 0; i < n; i++) {
			if (avg <= bread[i]) {
				ret += bread[i];
			} else {
				ret += avg;
			}
		}
		cout << ret << '\n';
	}
}