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
//BOJ #12738
vector<int> ret;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	ret.push_back(-1000000001);
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (ret.back() < num) {
			ret.push_back(num);
		} else {
			*lower_bound(ret.begin(), ret.end(), num) = num;
		}
	}
	cout << ret.size() - 1;
}
