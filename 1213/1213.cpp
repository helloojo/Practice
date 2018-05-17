#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//BOJ #1213

int cnt[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A']++;
	}
	bool ok = true;
	string ret = "";
	int oddcnt = 0;
	bool odd = false;
	if (s.size() & 1) {
		odd = true;
	}
	string mid = "";
	for (int i = 0; i < 26; i++) {
		if (cnt[i] & 1) {
			oddcnt++;
			if (odd) {
				if (oddcnt > 1) {
					ok = false;
					break;
				} else {
					mid = (i + 'A');
					cnt[i]--;
				}
			} else {
				ok = false;
				break;
			}
		}
		while (cnt[i] != 0) {
			ret += (i + 'A');
			cnt[i] -= 2;
		}
	}
	if (ok) {
		string temp = ret;
		reverse(temp.begin(), temp.end());
		if (odd) {
			ret += (mid + temp);
		} else {
			ret += temp;
		}
		cout << ret;
	} else {
		cout << "I'm Sorry Hansoo";
	}
}