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
//BOJ #2729
typedef long long ll;
typedef unsigned long long ull;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string a, b, c;
		cin >> a >> b;
		int carry = 0;
		int i;
		for (i = 0;i<a.size(); i++) {
			if (a[i] == '1') {
				break;
			}
		}
		a = a.substr(i);
		for (i = 0; i < b.size(); i++) {
			if (b[i] == '1') {
				break;
			}
		}
		b = b.substr(i);
		for (int i = a.size() - 1, j = b.size() - 1;;) {
			if (i < 0 && j < 0) {
				break;
			} else if (i < 0) {
				while (j >= 0) {
					int cal = b[j--] - '0';
					if (carry) {
						cal += 1;
						carry = 0;
					}
					if (cal > 1) {
						carry = 1;
						cal %= 2;
					}
					c.push_back(cal + '0');
				}
				break;
			} else if (j < 0) {
				while (i >= 0) {
					int cal = a[i--] - '0';
					if (carry) {
						cal += 1;
						carry = 0;
					}
					if (cal > 1) {
						carry = 1;
						cal %= 2;
					}
					c.push_back(cal + '0');
				}
				break;
			} else {
				int cal = a[i--] + b[j--] - '0' * 2;
				if (carry) {
					cal += 1;
					carry = 0;
				}
				if (cal > 1) {
					carry = 1;
					cal %= 2;
				}
				c.push_back(cal + '0');
			}
		}
		if (carry) {
			c.push_back('1');
		}
		reverse(c.begin(), c.end());
		cout << (c.empty() ? "0":c) << '\n';
	}
}
