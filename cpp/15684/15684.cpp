#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h;
bool map[32][12];

bool find_route(int y, int x, int start) {
  while (y != h + 1) {
    if (map[y][x]) {
      x++;
    } else if (map[y][x - 1]) {
      x--;
    }
    y++;
  }
  return x == start;
}

bool check() {
  for (int i = 1; i < n; i++) {
    if (!find_route(0, i, i)) {
      return false;
    }
  }
  return true;
}

int limit;

int find_solution(int here, int depth = 0) {
  if (depth == 3) {
    return check() ? depth : 4;
  }
  if (check()) {
    return depth;
  }
  int ret = 4;
  for (int i = here + 1; i < limit; i++) {
    int y = i / (n - 1) + 1;
    int x = i % (n - 1) + 1;
    if (map[y][x - 1] || map[y][x] || map[y][x + 1]) {
      continue;
    }
    map[y][x] = true;
    ret = min(ret, find_solution(i, depth + 1));
    map[y][x] = false;
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> h;
  limit = (n - 1) * h;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    map[a][b] = true;
  }
  int ret = find_solution(-1, 0);
  cout << (ret == 4 ? -1 : ret);
}