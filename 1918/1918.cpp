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
//BOJ #1918

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	stack<char> st;
	st.push('(');
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		} else if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			st.push(s[i]);
		} else {
			cout << s[i];
		}
	}
	while (st.top() != '(') {
		cout << st.top();
		st.pop();
	}
	st.pop();
}
