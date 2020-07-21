#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//BOJ #15783

int n, m;
vector<vector<int>> adj;
vector<vector<int>> adjrev;
stack<int> st;
int visited[100001];
int visit = 1;

void dfs(int here, vector<vector<int>>& adj, bool scc = false) {
  if (visited[here] == visit) {
    return;
  }
  visited[here] = visit;
  int size = adj[here].size();
  for (int i = 0; i < size; ++i) {
    dfs(adj[here][i], adj, scc);
  }
  if (!scc) {
    st.push(here);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  int a, b;
  adj.resize(n + 1);
  adjrev.resize(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adjrev[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    dfs(i, adj);
  }
  int ret = 0;
  visit++;
  int here;
  while (!st.empty()) {
    here = st.top();
    st.pop();
    if (visited[here] != visit) {
      dfs(here, adj, true);
      ret++;
    }
  }
  cout << ret << '\n';
}
