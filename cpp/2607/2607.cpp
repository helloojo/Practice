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
//BOJ #2607

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string ori;
	string cmp;
	cin >> ori;
	int oricnt[26] = { 0 };
	int size = ori.size();
	for (int i = 0; i < size; i++) {
		oricnt[ori[i] - 'A']++;
	}
	int ret = 0;
	for (int i = 1; i < n; i++) {
		cin >> cmp;
		if (abs((int)cmp.size() - size) > 1) {
			continue;
		}
		int cmpcnt[26] = { 0 };
		int cnt = 0;
		int cnt2 = 0;
		for (int j = 0; j < cmp.size(); j++) {
			cmpcnt[cmp[j] - 'A']++;
		}
		for (int j = 0; j < 26; j++) {
			cout << char(j + 'A') << ' ' << oricnt[j] << ' ' << cmpcnt[j] << endl;
			if (abs(cmpcnt[j] - oricnt[j]) > 1) {
				cnt++;
			} else if (abs(cmpcnt[j] - oricnt[j] == 1)) {
				cnt2++;
			}
		}
		if (cnt == 0 && cnt2 <= 1) {
			ret++;
		}
	}
	cout << ret;
}

