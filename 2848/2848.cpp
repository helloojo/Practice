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
//BOJ #2848

string dic[101];
int map[27][27];
bool visited[27];
int in[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int count = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> dic[i];
		for (int j = 0; j < dic[i].size(); j++) {
			if (!visited[dic[i][j] - 'a']) {
				count++;
				visited[dic[i][j] - 'a'] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < dic[i].size() && k < dic[j].size(); k++) {
				int a = dic[i][k] - 'a';
				int b = dic[j][k] - 'a';
				if (a != b) {
					if (map[a][b] == 0) {
						map[a][b] = 1;
						in[b]++;
					}
					break;
				}
			}
		}
	}
	queue<int> q;
	vector<char> ret;
	for (int i = 0; i < 26; i++) {
		if (visited[i]) {
			if (in[i] == 0) {
				q.push(i);
				cnt++;
			}
		}
	}
	int can = true;

	while (!q.empty()) {
		if (q.size() > 1) {
			can = false;
		}
		int p = q.front();
		q.pop();
		ret.push_back(p + 'a');
		for (int i = 0; i < 26; i++) {
			if (map[p][i]) {
				in[i]--;
				if (in[i] == 0) {
					q.push(i);
					cnt++;
				}
			}
		}

	}
	if (cnt != count) {
		cout << "!";
	} else if (!can) {
		cout << "?";
	} else {
		for (int i = 0; i < ret.size(); i++) {
			cout << ret[i];
		}
	}
}
