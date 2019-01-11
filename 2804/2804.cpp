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
//BOJ #2804
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	int aa,bb;
	int n = a.size();
	int m = b.size();
	for (aa = 0; aa < n; aa++) {
		bool flag = false;
		for (bb = 0; bb < m; bb++) {
			if (a[aa] == b[bb]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	char map[31][31] = { 0 };
	for (int i = 0; i < n; i++) {
		map[bb][i] = a[i];
	}
	for (int i = 0; i < m; i++) {
		map[i][aa] = b[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				cout << map[i][j];
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}
}
