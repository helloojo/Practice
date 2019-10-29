#include <iostream>
#include <algorithm>
using namespace std;

int map[21][21];
int visited[21][21];
int visit;
int answer = 987654321;

void calculate_min_max(int& maxn, int& minn, int& sum) {
  maxn = max(maxn, sum);
  minn = min(minn, sum);
  sum = 0;
}

void calculate_min_value(int n, int sy, int sx, int ly, int lx, int ry, int rx, int cy, int cx) {
  int max_sum = 0;
  int min_sum = 987654321;
  int idx = 0;
  int sum = 0;
  //1¹ø
  for (int i = 0; i < ly; i++) {
    int dj;
    if (i < sy) {
      dj = sx + 1;
    } else {
      dj = sx - (idx++);
    }
    for (int j = 0; j < dj; j++) {
      sum += map[i][j];
      visited[i][j] = visit;
    }
  }
  calculate_min_max(max_sum, min_sum, sum);
  idx = 0;
  //2¹ø
  for (int i = 0; i < ry + 1; i++) {
    int sj;
    if (i <= sy) {
      sj = sx + 1;
    } else {
      sj = sx + 1 + (++idx);
    }
    for (int j = sj; j < n; j++) {
      sum += map[i][j];
      visited[i][j] = visit;
    }
  }
  calculate_min_max(max_sum, min_sum, sum);
  idx = 0;
  //3¹ø
  for (int i = ly; i < n; i++) {
    int dj;
    if (i < cy) {
      dj = lx+idx++;
    } else {
      dj = cx;
    }
    for (int j = 0; j < dj; j++) {
      sum += map[i][j];
      visited[i][j] = visit;
    }
  }
  calculate_min_max(max_sum, min_sum, sum);
  idx = 0;
  for (int i = ry + 1; i < n; i++) {
    int sj;
    if (i <= cy) {
      sj = rx - idx++;
    } else {
      sj = cx;
    }
    for (int j = sj; j < n; j++) {
      sum += map[i][j];
      visited[i][j] = visit;
    }
  }
  calculate_min_max(max_sum, min_sum, sum);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j] != visit) {
        sum += map[i][j];
      }
    }
  }
  calculate_min_max(max_sum, min_sum, sum);
  answer = min(answer, max_sum - min_sum);
}

void find_cross_point(int n, int sy, int sx, int ly, int lx, int ry, int rx) {
  pair<int, int> right = { ry,rx };
  pair<int, int> left = { ly,lx };
  while (right.first != left.first) {
    if (right.first > left.first) {
      left.first++;
      left.second++;
    } else {
      right.first++;
      right.second--;
    }
  }
  while (right != left) {
    left.first++;
    left.second++;
    right.first++;
    right.second--;
  }
  visit++;
  calculate_min_value(n, sy, sx, ly, lx, ry, rx, right.first, right.second);
}

void find_right_point(int n, int sy, int sx, int ly, int lx) {
  int x = sx + 1;
  int y = sy + 1;
  while (x < n && y < n) {
    find_cross_point(n, sy, sx, ly, lx, y++, x++);
  }
}

void find_left_point(int n, int sy, int sx) {
  int x = sx - 1;
  int y = sy + 1;
  while (x >= 0 && y < n) {
    find_right_point(n, sy, sx, y++, x--);
  }
}

void find_answer(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      find_left_point(n, i, j);
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
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
  find_answer(n);
  cout << answer << '\n';
}