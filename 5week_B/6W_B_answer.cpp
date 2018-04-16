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
		int first = 0;
		int last = s.size();
		int next = last;
		while (true) {
			int next1 = next;
			if (s[--next] < s[next1]) {
				int mid = last;
				while (!(s[next] < s[--mid]));
				swap(s[next], s[mid]);
				for (int i = next1, j = last - 1; i < j; i++, j--) {
					swap(s[i], s[j]);
				}
				break;
			}
			if (next == first) {
				break;
			}
		}
		cout << s << '\n';
	}
	return 0;
}