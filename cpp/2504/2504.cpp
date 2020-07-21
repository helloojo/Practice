#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//BOJ #2504
vector<char> big;
vector<char> small;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<int> ret(100, 0);
	int size = 0;
	bool ok = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			small.push_back(s[i]);
			size++;
		}
		if (s[i] == '[') {
			big.push_back(s[i]);
			size++;
		}
		if (s[i] == ')') {
			if (small.empty()) {
				ok = false;
				break;
			}
			small.pop_back();
			if (i != 0 && s[i - 1] == '(') {
				size--;
				ret[size] += 2;
			} else {
				ret[size] *= 2;
				size--;
			}
		}
		if (s[i] == ']') {
			if (big.empty()) {
				ok = false;
				break;
			}
			big.pop_back();
			if (i != 0 && s[i - 1] == '[') {
				size--;
				ret[size] += 3;
			} else {
				ret[size] *= 3;
				size--;
			}
		}
		//if (big.empty() && small.empty()) {
		//	size++;
		//}
		if (size < 0) {
			size = 0;
		}
	}
	if (!big.empty() && !small.empty()) {
		ok = false;
	}
	int sum = 0;
	for (int i = 0; i < ret.size(); i++) {
		sum += ret[i];
		if (ret[i]) {
			cout << ret[i] << ' ';
		}
	}
	cout << endl;
	if (ok) {
		cout << sum;
	} else {
		cout << 0;
	}
	return 0;
}