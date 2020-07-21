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
//BOJ #
typedef long long ll;
typedef unsigned long long ull;
int arr[1001][1001];
pair<int, int> front[1001];
pair<int, int> side[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (front[j].first <= arr[i][j]) {
				front[j] = { arr[i][j],i };
			}
			if (side[i].first < arr[i][j]) {
				side[i] = { arr[i][j],j };
			}
		}
	}
	ull ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != front[j].first || front[j].second != i) {
				if (arr[i][j] != side[i].first || side[i].second != j) {
					ret += arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
	}
	cout << ret;
}
