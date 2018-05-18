#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//BOJ #2966

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string a = "ABC";
	string b = "BABC";
	string c = "CCAABB";
	string s;
	cin >> s;
	int cnt[3] = { 0 };
	string id[3] = { "Adrian","Bruno","Goran" };
	for (int i = 0, aa = 0,bb=0,cc=0; i < n; i++, aa++,bb++,cc++) {
		if (aa == a.size()) {
			aa = 0;
		}
		if (bb == b.size()) {
			bb = 0;
		}
		if (cc == c.size()) {
			cc = 0;
		}
		if (s[i] == a[aa]) {
			cnt[0]++;
		}
		if (s[i] == b[bb]) {
			cnt[1]++;
		}
		if (s[i] == c[cc]) {
			cnt[2]++;
		}
	}
	int maxcnt = *max_element(cnt, cnt + 3);
	cout << maxcnt << '\n';
	for (int i = 0; i < 3; i++) {
		if (maxcnt == cnt[i]) {
			cout << id[i] << '\n';
		}
	}
}