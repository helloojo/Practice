#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
//BOJ #10527

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	map<string, int> d;
	map<string, int> k;
	set<string> st;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		d[s]++;
		st.insert(s);
	}
	for (int i = 0; i < n; i++) {
		cin >> s;
		k[s]++;
		st.insert(s);
	}
	int ret = 0;
	for (auto i = st.begin(); i != st.end(); i++) {
		ret += min(d[*i], k[*i]);
	}
	cout << ret;
	return 0;
}