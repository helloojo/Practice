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
//BOJ #9935

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	string boom;
	cin >> s >> boom;
	char dst = boom.back();
	int size = boom.size();
	vector<char> st;
	for (int i = 0; i < s.size(); i++) {
		st.push_back(s[i]);
		if (s[i] == dst) {
			bool can = true;
			for (int j = st.size() - size,k=0; k<size; j++,k++) {
				if (st[j] != boom[k]) {
					can = false;
					break;
				}
			}
			if (can) {
				for (int j = 0; j < size; j++) {
					st.pop_back();
				}
			}
		}
	}
	for (int i = 0; i < st.size(); i++) {
		cout << st[i];
	}
}
