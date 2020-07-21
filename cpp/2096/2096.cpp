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
//BOJ #2096
typedef long long ll;
typedef unsigned long long ull;
int arr[3];
pair<int, int> ret[2][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
		}
		ret[i % 2][0].first = max(ret[(i + 1) % 2][0].first, ret[(i + 1) % 2][1].first) + arr[0];
		ret[i % 2][1].first = max({ ret[(i + 1) % 2][0].first,ret[(i + 1) % 2][1].first, ret[(i + 1) % 2][2].first }) + arr[1];
		ret[i % 2][2].first = max(ret[(i + 1) % 2][1].first, ret[(i + 1) % 2][2].first) + arr[2];
		ret[i % 2][0].second = min(ret[(i + 1) % 2][0].second, ret[(i + 1) % 2][1].second) + arr[0];
		ret[i % 2][1].second = min({ ret[(i + 1) % 2][0].second,ret[(i + 1) % 2][1].second, ret[(i + 1) % 2][2].second }) + arr[1];
		ret[i % 2][2].second = min(ret[(i + 1) % 2][1].second, ret[(i + 1) % 2][2].second) + arr[2];
	}
	cout << max({ ret[n%2][0].first,ret[n%2][1].first,ret[n%2][2].first }) << ' ' << min({ ret[n%2][0].second, ret[n%2][1].second,ret[n%2][2].second });
}
