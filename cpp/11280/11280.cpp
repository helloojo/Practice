#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> adjrev;
vector<int> sccidx;
vector<int> visited;
int visit = 1;
int sccnum = 0;
stack<int> st;

void dfs(int here, vector<vector<int>>& adj, bool scc = false) {
  if (visited[here] == visit) {
    return;
  }
  visited[here] = visit;
  if (scc) {
    sccidx[here] = sccnum;
  }
  for (int next : adj[here]) {
    dfs(next, adj, scc);
  }
  if (!scc) {
    st.push(here);
  }
}

int notnum(int num, int n) { return (n << 1) - num; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int graph_size = (n << 1) + 1;
  adj.resize(graph_size);
  adjrev.resize(graph_size);
  sccidx.resize(graph_size, -1);
  visited.resize(graph_size);
  int a, b;
  while (m--) {
    cin >> a >> b;
    a += n;
    b += n;
    adj[notnum(a, n)].push_back(b);
    adj[notnum(b, n)].push_back(a);
    adjrev[a].push_back(notnum(b, n));
    adjrev[b].push_back(notnum(a, n));
  }
  for (int i = 0; i < graph_size; i++) {
    if (i == n) continue;
    dfs(i, adj);
  }
  int here;
  visit++;
  while (!st.empty()) {
    here = st.top();
    st.pop();
    if (visited[here] != visit) {
      dfs(here, adjrev, true);
      sccnum++;
    }
  }

  bool can = true;
  for (int i = 0; i < n; i++) {
    if (sccidx[i] == sccidx[(n << 1) - i]) {
      can = false;
      break;
    }
  }
  cout << can;
  return 0;
}