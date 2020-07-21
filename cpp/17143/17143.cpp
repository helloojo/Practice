#include <iostream>
using namespace std;

struct Shark {
  int r;
  int c;
  int s;
  int d;
  int z;
  int alive;
} shark[10010];

Shark* map[102][102];

int pos[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };

int catch_shark(int r, int pos) {
  for (int i = 1; i <= r; i++) {
    if (map[i][pos]) {
      map[i][pos]->alive = 0;
      int weight = map[i][pos]->z;
      map[i][pos] = NULL;
      return weight;
    }
  }
  return 0;
}

void move(int r, int c, int m) {
  for (int i = 0; i < m; i++) {
    if (shark[i].alive) {
      Shark& s = shark[i];
      map[s.r][s.c] = NULL;
      int nx = s.c;
      int ny = s.r;
      int d = s.d - 1;
      switch (d) {
      case 0: //up
        if (s.s > ny - 1) {
          int dis = s.s - ny + 1;
          int cnt = dis / (r - 1);
          dis %= (r - 1);
          if (cnt & 1) {
            ny = r - dis;
          } else {
            ny = 1 + dis;
            d = 1;
          }
        } else {
          ny -= s.s;
          if (ny == 1) {
            d = 1;
          }
        }
        break;
      case 1: //down
        if (s.s > (r - ny)) {
          int dis = s.s - r + ny;
          int cnt = dis / (r - 1);
          dis %= (r - 1);
          if (cnt & 1) {
            ny = 1 + dis;
          } else {
            ny = r - dis;
            d = 0;
          }
        } else {
          ny += s.s;
          if (ny == r) {
            d = 0;
          }
        }
        break;
      case 2: //right
        if (s.s > (c - nx)) {
          int dis = s.s - c + nx;
          int cnt = dis / (c - 1);
          dis %= (c - 1);
          if (cnt & 1) {
            nx = 1 + dis;
          } else {
            nx = c - dis;
            d = 3;
          }
        } else {
          nx += s.s;
          if (nx == c) {
            d = 3;
          }
        }
        break;
      case 3: //left
        if (s.s > nx - 1) {
          int dis = s.s - nx + 1;
          int cnt = dis / (c - 1);
          dis %= (c - 1);
          if (cnt & 1) {
            nx = c - dis;
          } else {
            nx = 1 + dis;
            d = 2;
          }
        } else {
          nx -= s.s;
          if (nx == 1) {
            d = 2;
          }
        }
        break;
      }
      s.r = ny;
      s.c = nx;
      s.d = d + 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (shark[i].alive) {
      Shark& s = shark[i];
      if (map[s.r][s.c] == NULL) {
        map[s.r][s.c] = &shark[i];
      } else {
        if (map[s.r][s.c]->z < s.z) {
          map[s.r][s.c]->alive = 0;
          map[s.r][s.c] = &s;
        } else {
          s.alive = 0;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int R, C, M;
  cin >> R >> C >> M;

  for (int i = 0; i < M; i++) {
    cin >> shark[i].r >> shark[i].c;
    cin >> shark[i].s >> shark[i].d >> shark[i].z;
    shark[i].alive = 1;
    map[shark[i].r][shark[i].c] = &shark[i];
  }
  int answer = 0;
  for (int i = 1; i <= C; i++) {
    answer += catch_shark(R, i);
    move(R, C, M);
  }
  cout << answer << '\n';
}