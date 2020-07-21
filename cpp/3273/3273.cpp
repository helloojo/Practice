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
//BOJ #3273

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x;
	cin >> x;
	sort(arr, arr + n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int tmp = x - arr[i];
		auto lo = lower_bound(arr, arr + n, tmp);
		auto up = upper_bound(arr, arr + n, tmp);
		ret += (up - lo);
	}
	cout << ret;
}