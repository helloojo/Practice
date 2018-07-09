#include <iostream>
#include <string>
#include <vector>
using namespace std;
//BOJ #3986

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	vector<char> a, b;
	cin >> n;
	string s;
	int ret = 0;
	while (n--) {
		a.clear();
		b.clear();
		cin >> s;
		bool can = true;
		if (!(s.size() & 1)) {
			for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
				if (s[i] != s[j]) {
					can = false;
					break;
				}
			}
			if (!can) {
				can = true;
				for (int i = 0; i < s.size(); i++) {
					if (s[i] == 'A') {
						if (a.empty()) {
							a.push_back(s[i]);
						} else {
							if (s[i - 1] == 'A' && !b.empty()) {
								a.pop_back();
							} else if (b.empty()) {
								a.pop_back();
							} else {
								can = false;
								break;
							}
						}
					} else {
						if (b.empty()) {
							b.push_back(s[i]);
						} else {
							if (s[i - 1] == 'B' && !a.empty()) {
								b.pop_back();
							} else if (a.empty()) {
								b.pop_back();
							} else {
								can = false;
								break;
							}
						}
					}
				}
			}
		} else {
			can = false;
		}
		
		if (can) {
			ret++;
		}
	}
	cout << ret;
}