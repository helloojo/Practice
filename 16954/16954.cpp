#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #16954
typedef long long ll;
typedef unsigned long long ull;

int visited[10][9][9];
char map[10][9][9];
int pos[9][2] = { {1,1},{-1,1},{1,-1},{-1,-1},{0,1},{1,0},{0,-1},{-1,0},{0,0} };
int sec = 0;
struct coor {
  int x, y, sec;
};

void down() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      map[sec + 1][i][j] = map[sec][i][j];
    }
  }
  sec++;
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++) {
      if (i == 0) {
        map[sec][i][j] = '.';
      } else {
        map[sec][i][j] = map[sec][i - 1][j];
      }
    }
  }
}

int bfs(int y = 7, int x = 0) {
  queue<coor> q;
  q.push({ x,y,0 });
  visited[0][y][x] = true;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    if (map[p.sec][p.y][p.x] == '#') {
      continue;
    }
    if (p.y == 0 && p.x == 7) {
      return 1;
    }
    for (int i = 0; i < 9; i++) {
      int nx = p.x + pos[i][0];
      int ny = p.y + pos[i][1];
      int ns = (p.sec + 1 > 9 ? 9 : p.sec + 1);
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) {
        continue;
      }
      if (map[p.sec][ny][nx] == '#') {
        continue;
      }
      if (visited[ns][ny][nx]) {
        continue;
      }
      visited[ns][ny][nx] = true;
      q.push({ nx,ny,ns });
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> map[sec][i][j];
    }
  }
  for (int i = 0; i < 9; i++) {
    down();
  }
  cout << bfs();
}
