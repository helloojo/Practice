#include <iostream> 
using namespace std;
#define BLANK 0
#define RED 1
#define BLUE 2

struct Piece {
  int x;
  int y;
  int dir;
  int idx;
} pieces[11];

int graph[11][11];
int pos[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
int map[13][13];
Piece* piece_map[13][13];

pair<bool, int> can_go_calculate_direction(Piece& p, int n) {
  int dir = p.dir;
  int nx = p.x + pos[dir][0];
  int ny = p.y + pos[dir][1];
  if (nx<1 || ny<1 || nx>n || ny>n) {
    dir = ((dir & 1) ? dir - 1 : dir + 1);
    nx = p.x + pos[dir][0];
    ny = p.y + pos[dir][1];
    if (map[ny][nx] == BLUE) {
      return { false,dir };
    }
    return { true,dir };
  }
  if (map[ny][nx] == BLUE) {
    dir = ((dir & 1) ? dir - 1 : dir + 1);
    nx = p.x + pos[dir][0];
    ny = p.y + pos[dir][1];
    if (nx<1 || ny<1 || nx>n || ny>n) {
      return { false,dir };
    }
    if (map[ny][nx] == BLUE) {
      return { false,dir };
    }
  }
  return { true,dir };
}

bool move_piece(Piece& p, int n, int k) {
  if (piece_map[p.y][p.x] != &p) {
    return false;
  }
  auto res = can_go_calculate_direction(p, n);
  p.dir = res.second;
  if (res.first == false) {
    return false;
  }
  piece_map[p.y][p.x] = nullptr;
  int nx = p.x + pos[p.dir][0];
  int ny = p.y + pos[p.dir][1];
  int here = p.idx;
  if (map[ny][nx] == RED) {
    int prev = -1;
    bool can = true;
    while (can) {
      can = false;
      for (int i = 1; i <= k; i++) {
        if (i == prev) continue;
        if (graph[here][i]) {
          graph[here][i] = 0;
          graph[i][here] = 1;
          prev = here;
          here = i;
          can = true;
          break;
        }
      }
    }
  }
  if (piece_map[ny][nx] == nullptr) {
    piece_map[ny][nx] = &pieces[here];
  } else {
    int idx = piece_map[ny][nx]->idx;
    bool can = true;
    while (can) {
      can = false;
      for (int i = 1; i <= k; i++) {
        if (graph[idx][i]) {
          idx = i;
          can = true;
        }
      }
    }
    graph[idx][here] = 1;
  }

  here = piece_map[ny][nx]->idx;
  int cnt = 1;
  bool can = true;
  while (can) {
    can = false;
    pieces[here].x = nx;
    pieces[here].y = ny;
    for (int i = 1; i <= k; i++) {
      if (graph[here][i]) {
        here = i;
        can = true;
        cnt++;
        break;
      }
    }
  }
  return cnt >= 4;
}

bool move_pieces(int n, int k) {
  for (int i = 1; i <= k; i++) {
    if (move_piece(pieces[i], n, k)) {
      return true;
    }
  }
  return false;
}

int solve(int n, int k) {
  int turn = 1;
  while (turn <= 1000) {
    if (move_pieces(n, k)) {
      break;
    }
    turn++;
  }
  return (turn > 1000 ? -1 : turn);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> map[i][j];
    }
  }
  int x, y, d;
  for (int i = 1; i <= k; i++) {
    cin >> y >> x >> d;
    pieces[i] = { x,y,d - 1,i };
    piece_map[y][x] = &pieces[i];
  }
  cout << solve(n, k) << '\n';
}