#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
//BOJ #3982

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	map<string, bool> m;
	string t1, t2;
	int g1, g2;
	while (t--) {
		for (int i = 0; i < 16; i++) {
			cin >> t1 >> t2 >> g1 >> g2;
			if (g1 > g2) {
				if (m.find(t1)!=m.end()) {
					if (m[t1]) {
						m[t1] = true;
					} else {
						m[t1] = false;
					}
				} else {
					m[t1] = true;
				}
				m[t2] = false;
			} else {
				if (m.find(t2) != m.end()) {
					if (m[t2]) {
						m[t2] = true;
					} else {
						m[t2] = false;
					}
				} else {
					m[t2] = true;
				}
				m[t1] = false;
			}
		}
		for (auto i = m.begin(); i != m.end(); i++) {
			if (i->second) {
				cout << i->first << '\n';
			}
		}
		m.clear();
	}
	return 0;
}