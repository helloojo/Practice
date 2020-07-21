#include <iostream>
#include <string>
using namespace std;
//BOJ #1259

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	while (s != "0") {
		bool ok = true;
		for (int i = 0, j = s.size()-1; i < j; i++, j--) {
			if (s[i] != s[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
		cin >> s;
	}
}