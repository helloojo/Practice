#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
using namespace std;
//BOJ #1013
vector<string> ret;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	string s;
	regex r("[0-9]+");
	smatch m;
	while(t--) {
		cin>>s;
		while(regex_search(s, m, r)) {
			for(auto& ss:m) {
				ret.push_back(ss);
			}
			s = m.suffix();
		}
	}
	sort(ret.begin(), ret.end(), [](string& a, string& b)->bool {
		if(a.size()<b.size()) {
			return true;
		} else if (a.size()==b.size()) {
			for(int i = 0; i<a.size(); i++) {
				if(a[i]<b[i]) {
					return true;
				} else if(a[i]>b[i]) {
					return false;
				}
			}
		}
		return false;
	});
	for(auto it = ret.begin(); it!=ret.end(); it++) {
		cout<<*it<<'\n';
	}
	return 0;
}