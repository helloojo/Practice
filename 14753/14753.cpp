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
//BOJ #14753
typedef long long ll;
typedef unsigned long long ull;
int arr[10001];
int ret = -987654321;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ret = max({ arr[0] * arr[n - 1],
			  arr[0] * arr[1],
			  arr[n - 1] * arr[n - 2],
			  arr[0] * arr[1] * arr[2],
			  arr[0] * arr[1] * arr[n - 1],
			  arr[0] * arr[n - 2] * arr[n - 1],
			  arr[n - 1] * arr[n - 2] * arr[n - 3]
			  });
	cout << ret << '\n';
}
