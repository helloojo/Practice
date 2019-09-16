#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

bool find_all(int root, unordered_map<int, pair<vector<int>, int>>& tree) {
  queue<int> q;
  q.push(root);
  int v_cnt = 1;
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    for (auto& s : tree[p].first) {
      q.push(s);
      v_cnt++;
    }
  }
  return v_cnt == tree.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int u, v;
  int case_num = 1;

  while (true) {
    cin >> u >> v;
    if (u == -1 && v == -1) {
      break;
    }
    bool result = true;
    unordered_map<int, pair<vector<int>, int>> tree;

    while (true) {
      if (u == 0 && v == 0) {
        break;
      }
      if (tree.find(u) == tree.end()) {
        tree[u] = { vector<int>(),0 };
      }
      tree[u].first.push_back(v);
      if (tree.find(v) == tree.end()) {
        tree[v] = { vector<int>(),1 };
      } else {
        tree[v].second++;
      }
      cin >> u >> v;
    }
    if (tree.size()) {
      int root = 0;
      for (auto& p : tree) {
        if (p.second.second == 0) {
          if (root != 0) {
            result = false;
          } else {
            root = p.first;
          }
        }
        if (p.second.second > 1) {
          result = false;
        }
      }
      if (root == 0) {
        result = false;
      }
      if (!find_all(root, tree)) {
        result = false;
      }
    }
    cout << "Case " << case_num++ << (result ? " is a tree.\n" : " is not a tree.\n");
  }
  return 0;
}