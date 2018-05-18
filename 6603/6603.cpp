#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//BOJ #6603

int map[50][50];
int s[13];
int st[6];
int in = -1;
bool visit[50];
void dfs(int here) {
	st[++in] = here;
	visit[here] = true;
	if (in == 5) {
		for (int i = 0; i <= in; i++) {
			cout << st[i] << ' ';
		}
		cout << '\n';
		in--;
		return;
	}
	for (int i = 0; i < 50; i++) {
		if (map[here][i] && !visit[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	while (k != 0) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < k; i++) {
			for (int j = i+1; j < k; j++) {
				map[s[i]][s[j]] = 1;
			}
		}
		dfs(s[0]);
		cout << '\n';
		cin >> k;
	}
	return 0;
}