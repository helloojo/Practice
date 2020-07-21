#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #3986
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		stack<char> st;
		int len = s.size();
		for (int j = 0; j < len; j++) {
			if (st.empty()) {
				st.push(s[j]);
			} else {
				if (st.top() == s[j]) {
					st.pop();
				} else {
					st.push(s[j]);
				}
			}
		}
		if (st.empty()) {
			ret++;
		}
	}
	cout << ret;
}
