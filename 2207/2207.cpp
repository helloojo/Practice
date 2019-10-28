#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adjrev;
vector<int> sccidx;
vector<int> visited;
stack<int> st;
int visit = 1;
int sccnum;

int notnum(int num, int n) {
  return (n << 1) - num;
}

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int graph_size = (m << 1) + 1;
  adj.resize(graph_size);
  adjrev.resize(graph_size);
  visited.resize(graph_size);
  sccidx.resize(graph_size);
  int a, b;
  while (n--) {
    cin >> a >> b;
    a += m;
    b += m;
    adj[notnum(a, m)].push_back(b);
    adj[notnum(b, m)].push_back(a);
    adjrev[a].push_back(notnum(b, m));
    adjrev[b].push_back(notnum(a, m));
  }
  for (int i = 0; i <= (m << 1); ++i) {
    if (i == m) continue;
    dfs(i, adj);
  }
  visit++;
  while (!st.empty()) {
    int here = st.top();
    st.pop();
    if (visited[here] != visit) {
      dfs(here, adjrev, true);
      sccnum++;
    }
  }
  bool can = true;
  for (int i = 0; i < m; i++) {
    if (sccidx[i] == sccidx[notnum(i, m)]) {
      can = false;
      break;
    }
  }
  cout << (can ? "^_^" : "OTL");
}