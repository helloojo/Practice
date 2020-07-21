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
//BOJ #15740

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string temp;
	int up = 0;
	string a, b;
	cin >> a >> b;
	int am = 1;
	int bm = 1;
	if (a[0] == '-') {
		am = -1;
	}
	if (b[0] == '-') {
		bm = -1;
	}
	for (int i = b.size() - 1, j = a.size() - 1; i >= 0 || j >= 0;) {
		int cur = 0;
		if (i < 0) {
			cur = (a[j--] - '0')*am + up;
		} else if (j < 0) {
			cur = (b[i--] - '0')*bm + up;
		} else if (i >= 0 && j >= 0) {
			cur = (b[i--] - '0')*bm + (a[j--] - '0')*am + up;
		}
		up = 0;
		up += (cur / 10);
		cur %= 10;
		temp.push_back(cur + '0');
	}
	if (up) {
		temp.push_back(up + '0');
	}
	reverse(temp.begin(), temp.end());
	cout << temp;
}
