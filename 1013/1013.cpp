#include <iostream>
#include <string>
#include <regex>
using namespace std;
//BOJ #1013
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	string s;
	regex r("(100+1+|01)+");
	smatch m;
	while(t--) {
		cin>>s;
		if(regex_match(s,r)) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
	return 0;
}