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
//BOJ #3107

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	string ret = "";
	string temp = "";
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			cnt++;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			if (s[i - 1] == ':') {
				for (int j = 0; j < 8 - cnt; j++) {
					for (int k = 0; k < 4; k++) {
						ret.push_back('0');
					}
					ret.push_back(':');
				}
			} else {
				for (int j = 0; j < 4 - temp.size(); j++) {
					ret.push_back('0');
				}
				ret += temp;
				temp = "";
				ret.push_back(':');
			}
		} else {
			temp.push_back(s[i]);
		}
	}
	if (temp.size()) {
		for (int j = 0; j < 4 - temp.size(); j++) {
			ret.push_back('0');
		}
		ret += temp;
	} else {
		ret.pop_back();
		if (ret.size() != 39) {
			ret.push_back(':');
			for (int k = 0; k < 4; k++) {
				ret.push_back('0');
			}
		}
	}
	cout << ret;
}
