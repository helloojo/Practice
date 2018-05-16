#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #2805
typedef long long ll;
ll arr[1000000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	ll low = 0;
	ll high = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		high = max(high, arr[i]);
	}
	ll mid = (low + high) / 2;
	while (low + 1 < high) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] - mid >= 0) {
				sum += (arr[i] - mid);
			}
		}
		if (sum < m) {
			high = mid;
		} else if(sum>m) {
			low = mid;
		} else {
			break;
		}
		mid = (low + high) / 2;
	}
	cout << mid;
}