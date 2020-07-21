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
	while (t--) {
		cin >> s;
		if (next_permutation(s.begin(), s.end())) {
			cout << s << '\n';
		} else {
			prev_permutation(s.begin(), s.end());
			cout << s << '\n';
		}
	}
	return 0;
}