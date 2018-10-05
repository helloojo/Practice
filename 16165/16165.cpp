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
//BOJ #16165
typedef long long ll;
typedef unsigned long long ull;
unordered_map<string, vector<string>> team;
unordered_map<string, string> member;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	string tm;
	string mb;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> tm;
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> mb;
			team[tm].push_back(mb);
			member[mb] = tm;
		}
		sort(team[tm].begin(), team[tm].end());
	}
	for (int i = 0; i < m; i++) {
		cin >> tm;
		cin >> num;
		switch (num) {
		case 1:
			cout << member[tm] << '\n';
			break;
		case 0:
			for (auto& i : team[tm]) {
				cout << i << '\n';
			}
			break;
		}
	}
}
