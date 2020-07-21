#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//BOJ #1068

vector<int> adj[51];
queue<int> q;
int bfs(int root,int del) {
	q.push(root);
	int ret = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == del) continue;
		int si = adj[p].size();
		if (si == 0) {
			ret++;
		}
		for (int i = 0; i < si; i++) {
			if (adj[p][i] == del) {
				if (si - 1 == 0) {
					ret++;
				}
			}
			q.push(adj[p][i]);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int num;
	int root = -1;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == -1) {
			root = i;
		} else {
			adj[num].push_back(i);
		}
	}
	int del;
	cin >> del;
	adj[del].clear();
	cout<<bfs(root, del);
}