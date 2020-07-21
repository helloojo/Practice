#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #7795

int arr[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		int num = 0;
		int ret = 0;
		for (int i = 0; i < m; i++) {
			cin >> num;
			for (int j = n-1; j >=0; j--) {
				if (arr[j] <= num) {
					break;
				}
				ret++;
			}
		}
		cout << ret << '\n';
	}
}
