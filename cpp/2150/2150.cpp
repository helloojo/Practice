#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adjrev;
vector<vector<int>> scc;
stack<int> st;
int visited[10001];
int visit = 1;

void dfs(int here, vector<vector<int>>& adj, int sccidx = -1) {
  if (visited[here] == visit) {
    return;
  }
  visited[here] = visit;
  if (sccidx != -1) {
    scc[sccidx].push_back(here);
  }

  int size = adj[here].size();
  for (int i = 0; i < size; i++) {
    dfs(adj[here][i], adj, sccidx);
  }

  if (sccidx == -1) {
    st.push(here);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int v, e;
  cin >> v >> e;
  adj = vector<vector<int>>(v + 1);
  adjrev = vector<vector<int>>(v + 1);
  int a, b;
  for (int i = 0; i < e; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adjrev[b].push_back(a);
  }
  for (int i = 1; i <= v; i++) {
    dfs(i, adj);
  }
  visit++;
  int sccidx = 0;
  while (!st.empty()) {
    int top = st.top();
    st.pop();
    if (visited[top] != visit) {
      scc.push_back(vector<int>());
      dfs(top, adjrev, sccidx++);
      sort(scc[sccidx - 1].begin(), scc[sccidx - 1].end());
    }
  }
  sort(scc.begin(), scc.end(), [](vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
    });
  cout << sccidx << '\n';
  for (int i = 0; i < sccidx; i++) {
    for (int j = 0; j < scc[i].size(); j++) {
      cout << scc[i][j] << ' ';
    }
    cout << -1 << '\n';
  }
}