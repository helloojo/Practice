#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #7569

int m, n, h;
int map[101][101][101];
bool visited[101][101][101];

int pos[6][3] = { {0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} };
struct tomato {
  int x;
  int y;
  int z;
  int time;
};
queue<tomato> q;

int bfs(int all) {
  int ret = 0;
  int cnt = 0;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    ret = max(ret, p.time);
    for (int i = 0; i < 6; i++) {
      int nx = p.x + pos[i][0];
      int ny = p.y + pos[i][1];
      int nz = p.z + pos[i][2];
      if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) {
        continue;
      }
      if (visited[nz][ny][nx] || map[nz][ny][nx] == -1) {
        continue;
      }
      visited[nz][ny][nx] = true;
      cnt++;
      if (map[nz][ny][nx] == 0) {
        map[nz][ny][nx] = 1;
      }
      q.push({ nx,ny,nz,p.time + 1 });
    }
  }
  return (cnt == all ? ret : -1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m >> n >> h;
  int all = m * n * h;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> map[i][j][k];
        if (map[i][j][k] == -1) {
          all--;
        } else if (map[i][j][k] == 1) {
          all--;
          visited[i][j][k] = true;
          q.push({ k,j,i,0 });
        }
      }
    }
  }

  int ret = bfs(all);
  cout << ret;
}