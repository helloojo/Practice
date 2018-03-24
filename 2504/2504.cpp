#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
//BOJ #2504
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	stack<char> st;
	cin>>s;
	bool good = true;
	vector<int> oper;
	int index = 0;
	for(int i = 0; i<s.size(); i++) {
		switch(s[i]) {
		case '(':
			st.push(s[i]);
			oper.push_back(2);
			index++;
			break;
		case '[':
			st.push(s[i]);
			oper.push_back(3);
			index++;
			break;
		case ')':
			if(st.empty() || st.top()==']') {
				good = false;
				break;
			} else {
				
				st.pop();
			}
			break;
		case ']':
			if(st.empty() || st.top()==')') {
				good = false;
				break;
			} else {
				oper.push_back(1);
				index++;
				st.pop();
			}
			break;
		}
	}
	int ret = 0;
	if(st.empty() && good) {
		for(int i = 0; i<=index; i++) {
			cout<<oper[i]<<' ';
			if(oper[i]!=1)
				ret += oper[i];
		}
		cout<<ret;
	} else {
		cout<<0;
	}
	return 0;
}