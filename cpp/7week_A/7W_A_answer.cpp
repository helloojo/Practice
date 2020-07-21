#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	string s;
	int a;
	while (t--) {
		cin >> s;
		a = stoi(s);
		reverse(s.begin(), s.end());
		a += stoi(s);
		s = to_string(a);
		bool yes = true;
		for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
			if (s[i] != s[j]) {
				yes = false;
			}
		}
		cout << (yes ? "YES\n" : "NO\n");
	}
}