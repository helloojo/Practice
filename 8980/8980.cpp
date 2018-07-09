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
//BOJ #8980

int info[2001][2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, c;
	cin >> n >> c;
	int m;
	cin >> m;
	int src, dst, cnt;
	for (int i = 0; i < m; i++) {
		cin >> src >> dst >> cnt;
		info[src][dst] = cnt;
	}
	int cur;
	for (int i = 1; i <= n; i++) {

	}
}
