#include <iostream>
#include <deque>
using namespace std;

int map[51][51];
int visited[51][51];
int visit = 0;
pair<int, int> virus[10];
int vidx;
int vselect[10];
int all;

int pos[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

static inline int max(int a, int b) {
  return (a > b ? a : b);
}

static inline int min(int a, int b) {
  return (a < b ? a : b);
}

int simulate(int n, int m) {
  deque<pair<int, pair<int, int>>> q;
  int cnt = 0;
  if (cnt == all) {
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int idx = vselect[i];
    visited[virus[idx].first][virus[idx].second] = visit;
    q.push_back({ 0,virus[idx] });
  }
  int ret = 0;
  while (!q.empty()) {
    int time = -q.front().first;
    auto p = q.front().second;
    q.pop_front();
    if (map[p.first][p.second] == 2) {
      ret = max(ret, time - 1);
    } else {
      ret = max(ret, time);
    }
    for (int i = 0; i < 4; i++) {
      int nx = p.second + pos[i][0];
      int ny = p.first + pos[i][1];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
        continue;
      }
      if (visited[ny][nx] == visit) {
        continue;
      }
      if (map[ny][nx] == 1) {
        continue;
      }
      visited[ny][nx] = visit;
      if (map[ny][nx] == 0) {
        cnt++;
      }
      //if (map[ny][nx] == 2) {
        //q.push_front({ -time, {ny,nx} });
      //} else {
        q.push_back({ -(time + 1), {ny,nx} });
      //}
    }
  }
  return (cnt == all ? ret : 987654321);
}

int find_min_time(int n, int m, int here = -1, int vcnt = 0) {
  if (vcnt == m) {
    visit++;
    int ret = simulate(n, m);
    return ret;
  }
  int ret = 987654321;
  for (int i = here + 1; i < vidx; i++) {
    vselect[vcnt] = i;
    ret = min(ret, find_min_time(n, m, i, vcnt + 1));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2) {
        virus[vidx++] = { i,j };
      }
      if (map[i][j] == 0) {
        ++all;
      }
    }
  }
  int result = find_min_time(n, m);
  cout << (result == 987654321 ? -1 : result);
}