#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;


int map[51][51];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int all_pos[8][2];
int dist[9][9];
int n, m;

void find_distance(int y, int x, int base) {
  int visited[51][51] = { 0 };
  queue<pair<int, pair<int, int>>> q;
  visited[y][x] = 1;
  q.push({ 1,{ y,x } });
  while (!q.empty()) {
    int dis = q.front().first;
    auto p = q.front().second;
    q.pop();
    if (map[p.first][p.second] > 0) {
      dist[base][map[p.first][p.second]] = visited[p.first][p.second] - visited[y][x];
    }
    for (int i = 0; i < 4; i++) {
      int nx = p.second + pos[i][0];
      int ny = p.first + pos[i][1];
      if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
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

int calc_distance(int here, int sum, int visited, int cnt, int allcnt, int finish) {
  if (visited == finish) {
    return sum;
  }
  int ret = 987654321;
  if (cnt == allcnt) {
    ret = min(ret, calc_distance(2, sum + dist[here][2], visited | (1 << 2), cnt, allcnt, finish));
    return ret;
  }
  for (int i = 3; i < allcnt + 3; i++) {
    if (visited & (1 << i)) {
      continue;
    }
    ret = min(ret, calc_distance(i, sum + dist[here][i], visited | (1 << i), cnt + 1, allcnt, finish));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;
  int allcnt = 0;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      switch (c) {
      case 'S':
        map[i][j] = 1;
        all_pos[1][0] = i;
        all_pos[1][1] = j;
        break;
      case 'E':
        map[i][j] = 2;
        all_pos[2][0] = i;
        all_pos[2][1] = j;
        break;
      case '#':
        map[i][j] = -1;
        break;
      case '.':
        map[i][j] = 0;
        break;
      case 'X':
        map[i][j] = 3 + allcnt;
        all_pos[3 + allcnt][0] = i;
        all_pos[3 + allcnt++][1] = j;
        break;
      }
    }
  }
  int check = 0;
  for (int i = 1; i < 3 + allcnt; i++) {
    check |= (1 << i);
    find_distance(all_pos[i][0], all_pos[i][1], i);
  }
  cout << calc_distance(1, 0, (1<<1), 0, allcnt,check);
}