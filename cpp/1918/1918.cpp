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
//BOJ #1918
typedef long long ll;
typedef unsigned long long ull;
stack<char> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		} else if (s[i] == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		} else if (s[i] == '*' || s[i] == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(s[i]);
		} else if (s[i] == '+' || s[i] == '-') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top()=='+' || st.top()=='-')) {
				cout << st.top();
				st.pop();
			}
			st.push(s[i]);
		} else {
			cout << s[i];
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
