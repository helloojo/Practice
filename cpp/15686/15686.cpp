#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


int n, m;
int map[51][51];
pair<int, int> chicken[14];
int selected[14];
int ch_idx;
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int chicken_distance[101][14];
int house_cnt;

int visited[51][51];
int visit;

void calculate_chicken_distance(int idx) {
  int sx = chicken[idx].second;
  int sy = chicken[idx].first;
  queue<pair<int, int>> q;
  q.push({ sy,sx });
  visited[sy][sx] = visit;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = p.second + pos[i][0];
      int ny = p.first + pos[i][1];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
        continue;
      }
      if (visited[ny][nx] == visit) {
        continue;
      }
      if (map[ny][nx]) {
        int h_idx = map[ny][nx] - 3;
        chicken_distance[h_idx][idx] = abs(ny - sy) + abs(nx - sx);
      }
      visited[ny][nx] = visit;
      q.push({ ny,nx });
    }
  }
}

int calculcate_min_chicken_distance(int here=-1, int cnt = 0) {
  if (cnt == m) {
    int ret = 0;
    for (int i = 0; i < house_cnt; i++) {
      int min_dis = 987654321;
      for (int j = 0; j < cnt; j++) {
        min_dis = min(min_dis, chicken_distance[i][selected[j]]);
      }
      ret += min_dis;
    }
    return ret;
  }
  int ret = 987654321;
  for (int i = here + 1; i < ch_idx; i++) {
    selected[cnt] = i;
    ret = min(ret, calculcate_min_chicken_distance(i, cnt + 1));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      if (map[i][j] == 2) {
        chicken[ch_idx++] = { i,j };
        map[i][j] = 0;
      } else if (map[i][j] == 1) {
        map[i][j] = house_cnt++ + 3;
      }
    }
  }
  for (int i = 0; i < ch_idx; i++) {
    ++visit;
    calculate_chicken_distance(i);
  }
  cout << calculcate_min_chicken_distance();
  return 0;
}