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
//BOJ #15818
typedef unsigned long long ull;
int num[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int ret = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		ret *= (num[i] % m);
	}
	cout << ret % m;
}
