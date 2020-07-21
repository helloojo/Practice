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
//BOJ #1865
typedef long long ll;
typedef unsigned long long ull;
int n, m, w;
struct Edge {
	int src;
	int dest;
	int weight;
};

vector<Edge> adj;

bool bellman(int src = 1) {
	vector<int> dis(n + 1, 987654321);
	dis[src] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < adj.size(); j++) {
			int s = adj[j].src;
			int d = adj[j].dest;
			int weight = adj[j].weight;
			if (dis[s] != 987654321 && dis[s] + weight < dis[d]) {
				dis[d] = dis[s] + weight;
			}
		}
	}
	for (int j = 0; j < adj.size(); j++) {
		int s = adj[j].src;
		int d = adj[j].dest;
		int weight = adj[j].weight;
		if (dis[s] != 987654321 && dis[s] + weight < dis[d]) {
			return true;
		}
	}
	return (dis[1] < 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		adj.clear();
		cin >> n >> m >> w;
		int s, e, t;
		while (m--) {
			cin >> s >> e >> t;
			adj.push_back({ s,e,t });
			adj.push_back({ e,s,t });
		}
		while (w--) {
			cin >> s >> e >> t;
			adj.push_back({ s,e,-t });
		}
		if (bellman()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
