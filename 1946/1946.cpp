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
//BOJ #1946

pair<int, int> arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		sort(arr, arr + n);
		int ret = 0;
		pair<int, int> cmp = arr[0];
		for (int i = 0; i < n; i++) {
			if (!(arr[i].first > cmp.first && arr[i].second > cmp.second)) {
				ret++;
				cmp = arr[i];
			}
		}
		cout << ret << '\n';
	}
}
