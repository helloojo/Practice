#include <iostream>
#include <string>
#include <map>
using namespace std;
//BOJ #1620

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s;
	map<string, int> m1;
	map<int, string> m2;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		m1[s] = i;
		m2[i] = s;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			cout << m2[stoi(s)] << '\n';
		} else {
			cout << m1[s] << '\n';
		}
	}
	return 0;
}