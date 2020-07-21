#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adjrev;
stack<int> st;
int sccidx[4010];
int visited[4010];
int visit = 0;
int sccnum = 0;

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

int notnum(int num, int n) {
  return (n << 1) - num;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  while (cin >> n >> m) {
    int graph_size = (n << 1) + 1;
    sccnum = 0;
    visit++;
    adj.clear();
    adjrev.clear();
    adj.resize(graph_size);
    adjrev.resize(graph_size);
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
    adj[notnum(1 + n, n)].push_back(1 + n);
    adjrev[1+n].push_back(notnum(1 + n,n));
    for (int i = 0; i < graph_size; i++) {
      if (i == n) continue;
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
    for (int i = 0; i < n; i++) {
      if (sccidx[i] == sccidx[notnum(i, n)]) {
        can = false;
        break;
      }
    }
    cout << (can ? "yes\n" : "no\n");
  }
  return 0;
}