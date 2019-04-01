#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #16466
typedef long long ll;
typedef unsigned long long ull;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int ret = 1;
	for (int i = 0; i < n; i++) {
		if (ret < arr[i]) {
			break;
		} else {
			if (i == n - 1) {
				ret = arr[i] + 1;
			} else {
				if (arr[i + 1] - arr[i] == 1) {
					ret++;
				} else {
					ret = arr[i] + 1;
					break;
				}
			}
		}
	}
	printf("%d", ret);
}
