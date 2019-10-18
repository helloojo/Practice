#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pos[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
bool map[110][110];

void make_dragon_curve(int y, int x, int d, int g) {
  vector<int> gene;
  gene.push_back(d);
  map[y][x] = true;
  x = x + pos[d][0];
  y = y + pos[d][1];
  map[y][x] = true;
  for (int i = 0; i < g; i++) {
    for (int j = gene.size() - 1; j >= 0; j--) {
      int d = (gene[j] + 1) % 4;
      x = x + pos[d][0];
      y = y + pos[d][1];
      map[y][x] = true;
      gene.push_back(d);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;
    make_dragon_curve(y, x, d, g);
  }
  int ret = 0;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      if (i + 1 <= 100 && j + 1 <= 100) {
        if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
          ret++;
        }
      }
    }
  }
  cout << ret;
}
