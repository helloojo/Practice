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
//BOJ #10219
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		char p[12][12];
		int h, w;
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> p[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = w - 1; j >= 0; j--) {
				cout << p[i][j];
			}
			cout << '\n';
		}
	}
}
