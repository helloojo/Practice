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
//BOJ #12015

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(1, 0);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (v.back() < num) {
			v.push_back(num);
		} else {
			*lower_bound(v.begin(), v.end(), num) = num;
		}
	}
	cout << v.size() - 1;
}
