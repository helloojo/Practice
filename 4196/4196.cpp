#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
stack<int> st;
int visit = 0;
int visited[100001];


void dfs(int here, vector<vector<int>>& adj, bool scc = false) {
  if (visited[here] == visit) {
    return;
  }
  visited[here] = visit;
  int size = adj[here].size();
  for (int i = 0; i < size; i++) {
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
  int t;
  cin >> t;
  while (t--) {
    visit++;
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    int x, y;
    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
      dfs(i, adj);
    }
    int ret = 0;
    visit++;
    while (!st.empty()) {
      int here = st.top();
      st.pop();
      if (visited[here] != visit) {
        ret++;
        dfs(here, adj, true);
      }
    }
    cout << ret << '\n';
    adj.clear();
  }
  
}