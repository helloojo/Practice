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
//BOJ #1072

typedef long long ull;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ull x, y;
	while (cin >> x >> y) {
		ull z = y * 100 / x;
		ull left = 1;
		ull right = 1000000000;
		ull mid = 0;
		ull tmp = 0;
		ull ret = 9987654321;
		while (left <= right) {
			mid = (left + right) / 2;
			tmp = (y + mid) * 100 / (x + mid);
			if (tmp > z) {
				ret = min(ret, mid);
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		cout << (ret == 9987654321 ? -1 : ret) << '\n';
	}
}
