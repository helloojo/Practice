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
//BOJ #10775

int parent[100001];
bool check[100001];

int find(int here) {
	if (!check[here]) {
		return here;
	}
	if (parent[here] == 0) {
		return here;
	}
	return parent[here] = find(parent[here]);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int g, p;
	cin >> g >> p;
	for (int i = 1; i <= g; i++) {
		parent[i] = i - 1;
	}
	int num;
	int ret = 0;
	for (int i = 0; i < p; i++) {
		cin >> num;
		int here = find(num);
		check[here] = true;
		if (!check[here]) {
			break;
		}

		ret++;
	}
	cout << ret;
}