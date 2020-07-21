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
//BOJ #14728

pair<int, int> sub[101];
int memo[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> sub[i].first >> sub[i].second;
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = t; j >= sub[i].first; j--) {
			memo[j] = max(memo[j], memo[j - sub[i].first] + sub[i].second);
		}
	}
	cout << memo[t];
}
