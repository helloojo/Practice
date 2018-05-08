#include <iostream>
#include <vector>
using namespace std;
//BOJ #11725
vector<vector<int>> adj;
bool visited[100001];
int parent[100001];
void find_parent(int post, int here) {
	if (visited[here]) return;
	visited[here] = true;
	parent[here] = post;
	int si = adj[here].size();
	for (int i = 0; i < si; i++) {
		find_parent(here, adj[here][i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	adj = vector<vector<int>>(n + 1);
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	find_parent(0,1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}