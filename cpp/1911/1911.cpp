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
//BOJ #1911

pair<int, int> arr[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + n);
	int cur = arr[n - 1].first;
	int ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i].first >= cur) {
			int length = 0;
			if ((cur - arr[i].second) % l == 0) {
				length = (cur - arr[i].second) / l;
			} else {
				length = (cur - arr[i].second) / l + 1;
			}
			ret += length;
			cur -= (length*l);
		} else {
			while (i >= 0 && arr[i].first >= cur) {
				i--;
			}
			cur = arr[i++].first;
		}
	}
	cout << ret;
}
