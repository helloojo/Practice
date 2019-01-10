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
//BOJ #1966
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		pair<int,int> Q[101] = {};
		int num;
		int f=0, r=0;
		for (int i = 0; i < n; i++) {
			cin >> num;
			Q[f] = { num,i };
			f = (f + 1) % 101;
		}
		int count = 1;
		while (true) {
			auto mm = *max_element(Q, Q + 101);
			if (Q[r].first < mm.first) {
				Q[f] = Q[r];
				Q[r] = { -1,-1 };
				f = (f + 1) % 101;
				r = (r + 1) % 101;
			} else {
				if (Q[r].first==mm.first && Q[r].second == m) {
					break;
				} else {
					Q[r] = { -1,-1 };
					r = (r + 1) % 101;
					count++;
				}
			}
		}
		cout << count << '\n';
	}
}
