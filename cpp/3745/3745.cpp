#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
//BOJ #3745

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while (cin >> n) {
		vector<int> v;
		v.push_back(-INT_MAX);
		int num;
		for (int i = 1; i <= n; i++) {
			cin >> num;
			if (v.back() < num) {
				v.push_back(num);
			} else {
				*lower_bound(v.begin(), v.end(), num) = num;
			}
		}
		cout << v.size() - 1 << '\n';
	}
}
