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
//BOJ #1016

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	bool no[1000001] = { 0 };
	for (int i = 2; i*i <= 1000000; i++) {
		if (no[i]) continue;
		for (int j = i*i; j <= 1000000; j+=i) {
			no[j] = true;
		}
	}
	int ret = 0;
	vector<int> prime;
	for (int i = 2; i <= 1000000; i++) {
		if (!no[i]) {
			prime.push_back(i);
			cout << i << endl;
		}
	}
	cout << ret;
}
