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
//BOJ #2718

int memo[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int n;
	memo[1] = 1;
	memo[2] = 5;
	memo[3] = 11;
	for (int i = 0; i<t; i++) {
		cin >> n;
		for (int i = 4; i <= n; i++) {
			if (memo[i] == 0) {
				memo[i] = memo[i - 1]+memo[i - 2]+memo[i-3];
			}
		}
		cout << memo[n] << "\n";
	}
}
