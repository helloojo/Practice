#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//BOJ #

pair<int, int> pos[5001];
vector<int> samex[5001];
vector<int> samey[5001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pos[i].first >> pos[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (pos[i].first > pos[j].first || pos[i].second > pos[j].second) {
				continue;
			}
			if (pos[i].first == pos[j].first) {
				samex[i].push_back(pos[j].second);
			}
			if (pos[i].second == pos[j].second) {
				samey[i].push_back(pos[j].first);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < samey[i].size(); j++) {
			for (int k = 0; k < samex[i].size(); k++) {
				if (find(pos, pos + n, make_pair(samex[i][k], samey[i][j]))) {
					ret++;
				}
			}
		}
	}
	cout << ret;
	return 0;
}