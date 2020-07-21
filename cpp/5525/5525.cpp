#include <iostream>
#include <regex>
#include <algorithm>
#include <string>
using namespace std;
//BOJ #5525
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int m;
	cin >> n >> m;
	cin >> s;
	string reg = "I(OI){";
	reg += (to_string(n) + "}");
	regex r(reg);
	smatch ma;
	int ret = 0;
	while (regex_search(s, ma, r)) {
		ret++;
		s = s.substr(2);
	}
	cout << ret;
	return 0;
}