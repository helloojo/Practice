#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
//BOJ #1764

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	map<string, int> ma;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		ma[s]++;
	}
	for (int i = 0; i < m; i++) {
		cin >> s;
		ma[s]++;
	}
	int cnt = 0;
	vector<string> ret;
	for (auto i = ma.begin(); i != ma.end(); i++) {
		if (i->second == 2) {
			cnt++;
			ret.push_back(i->first);
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << ret[i] << '\n';
	}
	return 0;
}