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
//BOJ #14888
typedef long long ll;
typedef unsigned long long ull;

int arr[11];
int oper[4];
int n;

pair<int,int> calc(int level,int cal) {
	if (level >= n) {
		return { cal,cal };
	}
	int maxv = -1987654321;
	int minv = 1987654321;
	for (int i = 0; i < 4; i++) {
		if (oper[i]) {
			oper[i]--;
			pair<int, int> cmp;
			switch (i) {
			case 0:
				cmp = calc(level + 1, cal + arr[level]);
				break;
			case 1:
				cmp = calc(level + 1, cal - arr[level]);
				break;
			case 2:
				cmp = calc(level + 1, cal * arr[level]);
				break;
			case 3:
				cmp = calc(level + 1, cal / arr[level]);
				break;
			}
			maxv = max(maxv,cmp.first);
			minv = min(minv, cmp.second);
			oper[i]++;
		}
	}
	return { maxv,minv };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	pair<int, int> ret = calc(1, arr[0]);
	cout << ret.first << '\n';
	cout << ret.second << '\n';
}
