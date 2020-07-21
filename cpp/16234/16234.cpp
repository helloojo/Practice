#include <iostream>
#include <queue>
using namespace std;

int abs_(int num) {
  return (num < 0 ? -num : num);
}

int map[51][51];
int visited[51][51];
int visit_idx;
pair<int, int> companion[2501];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, l, r;

bool get_companion(int y, int x) {
  queue<pair<int, int>> q;
  visited[y][x] = visit_idx;
  int idx = 0;
  companion[idx++] = { y,x };
  pair<int, int> ret = { 1,map[y][x] };
  q.push({ y,x });
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = p.first + pos[i][1];
      int nx = p.second + pos[i][0];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
        continue;
      }
      if (visited[ny][nx] == visit_idx) {
        continue;
      }
      int diff = abs_(map[p.first][p.second] - map[ny][nx]);
      if (diff < l || diff > r) {
        continue;
      }
      visited[ny][nx] = visit_idx;
      companion[idx++] = { ny,nx };
      ret.first++;
      ret.second += map[ny][nx];
      q.push({ ny,nx });
    }
  }
  if (ret.first != 1) {
    int size = ret.second / ret.first;
    for (int i = 0; i < idx; i++) {
      map[companion[i].first][companion[i].second] = size;
    }
    return true;
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  bool finish = false;
  int ret = 0;
  while (!finish) {
    visit_idx++;
    int move_cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (visited[i][j] != visit_idx) {
          if (get_companion(i, j)) {
            move_cnt++;
          }
        }
      }
    }
    if (move_cnt == 0) {
      finish = true;
    } else {
      ret++;
    }
  }
  cout << ret;

  return 0;
}