#include <iostream>
#include <string>
using namespace std;
//BOJ #15104
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	string ss;
	cin >> s;
	int size = s.size();
	ss.push_back(s[0]);
	for (int i = 1; i < size; i++) {
		ss.push_back('#');
		ss.push_back(s[i]);
	}
	size = ss.size();
	bool can = true;
	for (int i = 0; i < size; i++) {
		int left = i - 1;
		int right = i + 1;
		if (ss[i] == '#') {
			int cnt = 0;
			while (left >= 0 && right < size) {
				if (ss[left] != ss[right]) {
					break;
				}
				cnt += 2;
				left--;
				right++;
			}
			if (cnt) {
				can = false;
				break;
			}
		}
	}
	if (can) {
		cout << "Odd.";
	} else {
		cout << "Or not.";
	}
	return 0;
}