#include <iostream>
#include <queue>
using namespace std;

struct dust {
  int x;
  int y;
  int sum;
};

int map[51][51];
int tempmap[51][51];

void copymap(int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      map[i][j] = tempmap[i][j];
      tempmap[i][j] = 0;
    }
  }
}

int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void spread(int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (map[i][j] != -1 && map[i][j] != 0) {
        int quantity = map[i][j] / 5;
        if (!quantity) {
          tempmap[i][j] += map[i][j];
          continue;
        }
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
          int nx = j + pos[k][0];
          int ny = i + pos[k][1];
          if (nx < 0 || ny < 0 || ny >= r || nx >= c) {
            continue;
          }
          if (map[ny][nx] == -1) {
            continue;
          }
          cnt++;
          tempmap[ny][nx] += quantity;
        }
        tempmap[i][j] += map[i][j] - quantity * cnt;
      } else if (map[i][j] == -1) {
        tempmap[i][j] = -1;
      }
    }
  }
}

void air_move(int r, int c, pair<int, int>& air_pos) {
  for (int i = air_pos.first - 1; i >= 0; i--) {
    tempmap[i][0] = tempmap[i - 1][0];
  }
  for (int i = 0; i < c - 1; i++) {
    tempmap[0][i] = tempmap[0][i + 1];
  }
  for (int i = 0; i < air_pos.first; i++) {
    tempmap[i][c - 1] = tempmap[i + 1][c - 1];
  }
  for (int i = c - 1; i > 1; i--) {
    tempmap[air_pos.first][i] = tempmap[air_pos.first][i - 1];
  }
  for (int i = air_pos.second + 1; i < r - 1; i++) {
    tempmap[i][0] = tempmap[i + 1][0];
  }
  for (int i = 0; i < c - 1; i++) {
    tempmap[r - 1][i] = tempmap[r - 1][i + 1];
  }
  for (int i = r - 1; i > air_pos.second; i--) {
    tempmap[i][c - 1] = tempmap[i - 1][c - 1];
  }
  for (int i = c - 1; i > 1; i--) {
    tempmap[air_pos.second][i] = tempmap[air_pos.second][i - 1];
  }
  tempmap[air_pos.first][1] = tempmap[air_pos.second][1] = 0;
}

int check_dust_quantity(int r, int c) {
  int sum = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (map[i][j] != -1) {
        sum += map[i][j];
      }
    }
  }
  return sum;
}

void print(int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << map[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int R, C, T;
  pair<int, int> air_pos;
  cin >> R >> C >> T;
  queue<dust> q;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> map[i][j];
      if (map[i][j] == -1) {
        air_pos.second = i;
      } else if (map[i][j]) {
        q.push({ j,i,map[i][j] });
      }
    }
  }
  air_pos.first = air_pos.second - 1;
  for (int t = 0; t < T; t++) {
    spread(R, C);
    air_move(R, C, air_pos);
    copymap(R, C);
    
  }
  print(R, C);
  cout << check_dust_quantity(R, C) << '\n';
  return 0;
}