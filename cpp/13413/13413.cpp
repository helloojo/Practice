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
//BOJ #13413

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string src, dst;
		cin >> src >> dst;
		int ret = 0;
		int w = 0;
		int b = 0;
		for (int i = 0; i < n; i++) {
			if (src[i] != dst[i]) {
				if (src[i] == 'W') {
					w++;
				} else {
					b++;
				}
			}
		}
		ret = min(w, b) + max(w, b) - min(w, b);
		cout << ret << '\n';
	}
}
