#include <iostream>
#include <cstring>
using namespace std;
//BOJ #2526

int visited[98];
int n, p;
int dfs(int here) {
	if (visited[here]) {
		return here;
	}
	visited[here] = true;
	int next = (n * here)%p;
	return dfs(next);
}
int dfscnt(int here) {
	if (visited[here]) {
		return 0;
	}
	int ret = 1;
	visited[here] = true;
	int next = (n*here) % p;
	ret+=dfscnt(next);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> p;
	int cyclestart = dfs((n*n) % p);
	memset(visited, 0, sizeof(visited));
	cout << dfscnt(cyclestart);
}