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
//BOJ #15970
typedef long long ll;
typedef unsigned long long ull;

pair<int, int> pos[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pos[i].second >> pos[i].first;
	}
	sort(pos, pos + n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i - 1, k = i + 1;; j--, k++) {
			bool find = false;
			int mind = 987654321;
			if (j >= 0) {
				if (pos[i].first == pos[j].first) {
					mind = min(mind,abs(pos[i].second - pos[j].second));
					find = true;
				}
			}
			if (k < n) {
				if (pos[i].first == pos[k].first) {
					mind = min(mind, abs(pos[i].second - pos[k].second));
					find = true;
				}
			}
			if (find) {
				ret += mind;
				break;
			}
		}
	}
	cout << ret;
}
