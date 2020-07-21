#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adjrev;
stack<int> st;
int sccidx[4010];
int visited[4010];
int visit;
int sccnum;

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
  return (num <= n ? num + n : num - n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    visit++;
    sccnum = 0;
    int n, m, k;
    cin >> n >> m >> k;
    int all_size = n + m;
    int graph_size = (all_size << 1) + 1;
    adj.clear();
    adjrev.clear();
    adj.resize(graph_size);
    adjrev.resize(graph_size);
    int a, b, c, d;
    while (k--) {
      cin >> a >> b >> c >> d;
      a += m;
      c += m;
      if (a == c && b == d) continue;
      if (a == c) {
        if (b < d) {
          adj[notnum(a, all_size)].push_back(a);
          adjrev[a].push_back(notnum(a, all_size));
        } else {
          adj[a].push_back(notnum(a, all_size));
          adjrev[notnum(a, all_size)].push_back(a);
        }
      } else if (b == d) {
        if (a < c) {
          adj[notnum(b, all_size)].push_back(b);
          adjrev[b].push_back(notnum(b, all_size));
        } else {
          adj[b].push_back(notnum(b, all_size));
          adjrev[notnum(b, all_size)].push_back(b);
        }
      } else {
        if (a > c) {
          b = notnum(b, all_size);
          d = notnum(d, all_size);
        }
        if (b > d) {
          a = notnum(a, all_size);
          c = notnum(c, all_size);
        }
        adj[notnum(b, all_size)].push_back(a);
        adjrev[a].push_back(notnum(b, all_size));
        adj[notnum(c, all_size)].push_back(a);
        adjrev[a].push_back(notnum(c, all_size));
        adj[notnum(a, all_size)].push_back(b);
        adjrev[b].push_back(notnum(a, all_size));
        adj[notnum(d, all_size)].push_back(b);
        adjrev[b].push_back(notnum(d, all_size));
        adj[notnum(a, all_size)].push_back(c);
        adjrev[c].push_back(notnum(a, all_size));
        adj[notnum(d, all_size)].push_back(c);
        adjrev[c].push_back(notnum(d, all_size));
        adj[notnum(b, all_size)].push_back(d);
        adjrev[d].push_back(notnum(b, all_size));
        adj[notnum(c, all_size)].push_back(d);
        adjrev[d].push_back(notnum(c, all_size));
      }
    }
    for (int i = 0; i < graph_size; i++) {
      if (i == all_size) continue;
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
    for (int i = 0; i < all_size; i++) {
      if (sccidx[i] == sccidx[notnum(i, all_size)]) {
        can = false;
        break;
      }
    }
    cout << (can ? "Yes\n" : "No\n");
  }
}