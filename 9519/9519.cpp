#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #9519

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x;
	cin >> x;
	string s;
	string temp;
	cin >> s;
	for (int i = 0; i < x; i++) {
		temp = "";
		for (int j = 0; j < s.size(); j += 2) {
			temp += s[j];
		}
		for (int j = 1; j < s.size(); j += 2) {
			temp += s[j];
		}
		s = temp;
	}
	cout << s;
}
