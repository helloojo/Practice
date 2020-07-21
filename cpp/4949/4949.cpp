#include <iostream>
#include <string>
#include <vector>
using namespace std;
//BOJ #4949
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin, s);
	vector<char> st;
	while(s!=".") {
		int si = s.size();
		st.clear();
		bool can = true;
		for(int i = 0; i<si; i++) {
			if(s[i]=='('||s[i]=='[') {
				st.push_back(s[i]);
			} else {
				if(s[i]==')') {
					if(st.empty() || st.back()=='[') {
						can = false;
					} else if(st.back()=='(') {
						st.pop_back();
					}
				} else if(s[i]==']') {
					if(st.empty() || st.back()=='(') {
						can = false;
					} else if(st.back()=='[') {
						st.pop_back();
					}
				}
			}
		}
		if(st.empty()&&can) {
			cout<<"yes\n";
		} else {
			cout<<"no\n";
		}
		getline(cin, s);
	}
	return 0;
}