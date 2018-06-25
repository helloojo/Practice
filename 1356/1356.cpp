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
//BOJ #1356

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int size = s.size();
	bool can = false;
	for (int i = 1; i < size - 1; i++) {
		int first = 1;
		for (int j = 0; j < i; j++) {
			first *= (s[j] - '0');
		}
		int second = 1;
		for (int j = i; j < size; j++) {
			second *= (s[j] - '0');
		}
		if (second == first) {
			can = true;
		}
	}
	if (can) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}
