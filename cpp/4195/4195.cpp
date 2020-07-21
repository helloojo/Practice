#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
//BOJ #4195

map<string, string> m;
map<string, int> s;

string find(string here) {
	if (m[here] == here) {
		return here;
	}
	return m[here] = find(m[here]);
}
void merge(string u, string v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	s[u] += s[v];
	m[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		m.clear();
		s.clear();
		string me = "0";
		m[me] = me;
		s[me] = 0;
		int f;
		cin >> f;
		string a, b;
		for (int i = 0; i < f; i++) {
			cin >> a >> b;
			if (!s[a]) {
				s[a] = 1;
				m[a] = a;
				if (!s[b]) {
					s[b] = 1;
					m[b] = b;
				}
				merge(a, b);
			} else {
				if (!s[b]) {
					s[b] = 1;
					m[b] = b;
				}
				merge(a, b);
			}
			cout << max(s[find(a)], s[find(b)]) << '\n';
		}
	}
}
