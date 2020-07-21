#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> fish;

int n;
int map[21][21];
int visited[21][21];
int visit;
int pos[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int calc_shark_distance(int fish_idx, int shark_size) {
  auto& f = fish[fish_idx].second;
  visited[f.first][f.second] = visit;
  queue<pair<int, pair<int, int>>> q;
  q.push({ 0,f });
  int ret = 987654321;
  while (!q.empty()) {
    int dis = q.front().first;
    auto p = q.front().second;
    q.pop();
    if (map[p.first][p.second] == 9) {
      return dis;
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
      if (map[ny][nx] != 9 && map[ny][nx] > shark_size) {
        continue;
      }
      visited[ny][nx] = visit;
      q.push({ dis + 1,{ny,nx} });
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  pair<int, int> shark_pos;
  int shark_size = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      if (map[i][j] == 9) {
        shark_pos = { i,j };
      } else if (map[i][j] != 0) {
        fish.push_back({ map[i][j] ,{i,j} });
      }
    }
  }
  int ret = 0;
  int shark_eat = 0;
  bool help = false;
  while (!help) {
    int min_idx = -1;
    int min_time = 987654321;
    for (int i = 0; i < fish.size(); i++) {
      if (fish[i].first != -1 && fish[i].first < shark_size) {
        ++visit;
        int t = calc_shark_distance(i, shark_size);
        if (t < min_time) {
          min_time = t;
          min_idx = i;
        }
      }
    }
    if (min_idx == -1) {
      help = true;
      continue;
    }
    fish[min_idx].first = -1;
    map[shark_pos.first][shark_pos.second] = 0;
    auto& p = fish[min_idx].second;
    map[p.first][p.second] = 9;
    shark_pos = p;
    ret += min_time;
    shark_eat++;
    if (shark_eat == shark_size) {
      shark_size++;
      shark_eat = 0;
    }
  }
  cout << ret << '\n';
}