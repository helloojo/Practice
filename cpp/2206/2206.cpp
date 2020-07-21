#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #2206

struct Status {
  int x;
  int y;
  int hit;
  int dis;
  Status(int _x, int _y, int _hit, int _dis) {
    x = _x;
    y = _y;
    hit = _hit;
    dis = _dis;
  }
};

bool operator<(const Status& a, const Status& b) {
  return a.dis > b.dis;
}

int n, m;
char map[1001][1001];
bool visited[1001][1001][2];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
priority_queue<Status> q;

int BFS() {
  int ret = 987654321;
  q.push(Status(0, 0, 0, 1));
  visited[0][0][0] = true;
  while (!q.empty()) {
    auto s = q.top();
    q.pop();
    if (s.x == m - 1 && s.y == n - 1) {
      ret = min(ret, s.dis);
    }
    for (int i = 0; i < 4; i++) {
      int nx = s.x + pos[i][0];
      int ny = s.y + pos[i][1];
      if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
        continue;
      }
      if ((map[ny][nx] == '1' && s.hit) || visited[ny][nx][s.hit]) {
        continue;
      }
      if (map[ny][nx] == '1') {
        visited[ny][nx][1] = true;
        q.push(Status(nx, ny, 1, s.dis + 1));
      } else {
        visited[ny][nx][s.hit] = true;
        q.push(Status(nx, ny, s.hit, s.dis + 1));
      }
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> map[i];
  }
  int ans = BFS();
  if (ans == 987654321) {
    cout << -1;
  } else {
    cout << ans;
  }

  return 0;
}