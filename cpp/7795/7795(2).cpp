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
			int left = 0;
			int right = n - 1;
			int tmp = 0;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (arr[mid] <= num) {
					left = mid + 1;
				} else {
					right = mid - 1;
					tmp = max(tmp, n - mid);
				}
			}
			ret += tmp;
		}
		cout << ret << '\n';
	}
}
