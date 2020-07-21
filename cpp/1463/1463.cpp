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
//BOJ #1463
typedef long long ll;
typedef unsigned long long ull;
int memo[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		memo[i] = 987654321;
	}
	for (int i = 2; i <= n; i++) {
		memo[i] = memo[i - 1] + 1;
		if (i % 2 == 0) {
			memo[i] = min(memo[i],memo[i / 2] + 1);
		}
		if (i % 3 == 0) {
			memo[i] = min(memo[i], memo[i / 3] + 1);
		}
	}
	cout << memo[n];
}
