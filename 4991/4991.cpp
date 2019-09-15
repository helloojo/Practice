#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[21][21];
int things_pos[12][2];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
long long dist[12][12];
int w, h;

void find_distance(int sy, int sx, int base) {
  int visited[21][21] = { 0 };
  visited[sy][sx] = 1;
  queue <pair<int, pair<int, int>>> q;
  q.push({ 1,{sy,sx} });
  while (!q.empty()) {
    int dis = q.front().first;
    auto p = q.front().second;
    q.pop();
    if (map[p.first][p.second] > 0) {
      dist[base][map[p.first][p.second]] = visited[p.first][p.second] - visited[sy][sx];
    }
    for (int i = 0; i < 4; i++) {
      int nx = p.second + pos[i][0];
      int ny = p.first + pos[i][1];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
        continue;
      }
      if (map[ny][nx] == -1 || visited[ny][nx]) {
        continue;
      }
      visited[ny][nx] = dis + 1;
      q.push({ dis + 1,{ny,nx} });
    }
  }
}

long long calc_distance(int here, long long sum, int visited, int all_cnt, int checked) {
  if (visited == checked) {
    return sum;
  }
  long long ret = 987654321;
  for (int i = 2; i < all_cnt; i++) {
    if (visited & (1 << i)) {
      continue;
    }
    ret = min(ret, calc_distance(i, sum + dist[here][i], visited | (1 << i), all_cnt, checked));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    char input;
    int dust_cnt = 2;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> input;
        switch (input) {
        case '*':
          map[i][j] = dust_cnt;
          things_pos[dust_cnt][0] = i;
          things_pos[dust_cnt++][1] = j;
          break;
        case 'o':
          map[i][j] = 1;
          things_pos[1][0] = i;
          things_pos[1][1] = j;
          break;
        case 'x':
          map[i][j] = -1;
          break;
        default:
          map[i][j] = 0;
          break;
        }
      }
    }
    int check = 0;
    for (int i = 1; i < dust_cnt; i++) {
      check |= (1 << i);
      find_distance(things_pos[i][0], things_pos[i][1], i);
      for (int j = 1; j < dust_cnt; j++) {
        if (i == j) continue;
        if (dist[i][j] == 0) {
          dist[i][j] = 987654321;
        }
      }
    }
    long long ret = calc_distance(1, 0, (1 << 1), dust_cnt, check);
    cout << (ret == 987654321 ? -1 : ret) << '\n';
    for (int i = 1; i < dust_cnt; i++) {
      for (int j = 1; j < dust_cnt; j++) {
        dist[i][j] = 0;
      }
    }
  }
  return 0;
}