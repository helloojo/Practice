#include <iostream>
#include <map>
#include <string>
using namespace std;
//BOJ #7785

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	map<string, bool> m;
	string a, b;
	while (n--) {
		cin >> a >> b;
		if (b == "enter") {
			m[a] = true;
		} else {
			m[a] = false;
		}
	}
	for (auto i = m.rbegin(); i != m.rend(); i++) {
		if ((*i).second) {
			cout << (*i).first << '\n';
		}
	}
	return 0;
}