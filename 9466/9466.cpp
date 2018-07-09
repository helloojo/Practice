#include <iostream>
#include <cstring>
using namespace std;
//BOJ #9466
bool cycle[100001];
bool visited[100001];
bool checked[100001];
int sel[100001];
int n;

void find_cycle(int here) {
	if (checked[here]) {
		return;
	}
	if (cycle[here]) {
		return;
	}
	checked[here] = true;
	cycle[here] = true;
	find_cycle(sel[here]);
}
void dfs(int here) {
	if (visited[here]) {
		cout << here << endl;
		find_cycle(here);
		return;
	}
	visited[here] = true;
	dfs(sel[here]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		memset(cycle, 0, sizeof(cycle));
		memset(visited, 0, sizeof(visited));
		memset(checked, 0, sizeof(checked));
		cin >> n;
		int ret = n;
		for (int i = 1; i <= n; i++) {
			cin >> sel[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!cycle[i] && !visited[i]) {
				dfs(i);
				checked[i] = true;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (cycle[i]) {
				ret--;
			}
		}
		cout << ret << '\n';
	}
}