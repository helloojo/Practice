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
//BOJ #1940

int arr[15001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int tmp = m - arr[i];
		auto lo=lower_bound(arr, arr + n, tmp);
		auto up=upper_bound(arr, arr + n, tmp);
		ret += (up - lo);
	}
	cout << ret/2;
}
