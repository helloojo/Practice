#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adjrev;
vector<int> scc;
vector<int> sccidx;
vector<int> visited;

vector<pair<int, vector<int>>> sccgraph;
stack<int> st;
int visit = 1;
int sidx = 0;

void dfs(int here, vector<vector<int>>& adj, bool canscc = false) {
  if (visited[here] == visit) {
    if (canscc) {
      if (sccidx[here] != sidx) {
        sccgraph[sidx].first++;
        sccgraph[sccidx[here]].second.push_back(sidx);
      }
    }
    return;
  }
  visited[here] = visit;
  if (canscc) {
    scc[sidx]++;
    sccidx[here] = sidx;
  }
  for (int next : adj[here]) {
    dfs(next, adj, canscc);
  }
  if (!canscc) {
    st.push(here);
  }
}

int calc(int src, int dst) {
  priority_queue<pair<int, int>> pq;
  pq.push({ scc[src],src });
  vector<int> dist(sidx, -1);
  dist[src] = scc[src];
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    for (int next : sccgraph[p.second].second) {
      if (dist[next] < dist[p.second] + scc[next]) {
        dist[next] = dist[p.second] + scc[next];
        pq.push({ dist[next],next });
      }
    }
  }
  return (dist[dst] == -1 ? 0 : dist[dst]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  adj.resize(n + 1);
  adjrev.resize(n + 1);
  sccidx.resize(n + 1, -1);
  visited.resize(n + 1, 0);
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adjrev[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    dfs(i, adj);
  }

  int here;
  visit++;
  while (!st.empty()) {
    here = st.top();
    st.pop();
    if (visited[here] != visit) {
      scc.push_back(0);
      sccgraph.push_back({ 0,vector<int>() });
      dfs(here, adjrev, true);
      sidx++;
    }
  }
  cout << calc(sccidx[s], sccidx[t]);
}