#include <iostream>
using namespace std;
char map[51][51];
int n, m;
int visited[51][51];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool find_cycle(int y, int x, char init_C, int cnt = 2) {
  if (visited[y][x]) {
    return true;
  }
  visited[y][x] = cnt;
  bool can = false;
  for (int i = 0; i < 4; i++) {
    int nx = pos[i][0] + x;
    int ny = pos[i][1] + y;
    if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
      continue;
    }
    if (map[ny][nx] != init_C) {
      continue;
    }
    if (cnt - 1 == visited[ny][nx]) {
      continue;
    }
    if (find_cycle(ny, nx, init_C, cnt + 1)) {
      can = true;
    }
  }
  return can;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  bool can = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        if (find_cycle(i, j, map[i][j])) {
          can = true;
        }
      }
    }
  }
  cout << (can ? "Yes" : "No");
}