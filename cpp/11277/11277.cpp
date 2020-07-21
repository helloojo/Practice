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

int notnum(int n) { return (n % 2 ? n - 1 : n + 1); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  adj.resize((n << 1) + 2);
  adjrev.resize((n << 1) + 2);
  sccidx.resize((n << 1) + 2, -1);
  visited.resize((n << 1) + 2);
  int a, b;
  while (m--) {
    cin >> a >> b;
    a = (a < 0 ? -(a + 1) * 2 : a * 2 - 1);
    b = (b < 0 ? -(b + 1) * 2 : b * 2 - 1);
    adj[notnum(a)].push_back(b);
    adj[notnum(b)].push_back(a);
    adjrev[a].push_back(notnum(b));
    adjrev[b].push_back(notnum(a));
  }
  for (int i = 0; i < 2 * n; i++) {
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
    if (sccidx[i * 2] == sccidx[i * 2 + 1]) {
      can = false;
      break;
    }
  }
  cout << can;
  return 0;
}