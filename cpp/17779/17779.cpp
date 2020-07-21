#include <iostream>
#include <algorithm>
using namespace std;

int map[21][21];
int visited[21][21];
int visit;

void calculate_min_max(int& maxn, int& minn, int& sum) {
  maxn = max(maxn, sum);
  minn = min(minn, sum);
  sum = 0;
}

int calculate(int n, int sy, int sx, int ly, int lx, int ry, int rx, int cy, int cx) {
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
      dj = lx + idx++;
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
  return max_sum - min_sum;
}

int find_cross_point(int n, int sy, int sx, int ly, int lx, int ry, int rx) {
  pair<int, int> right = { ry,rx };
  pair<int, int> left = { ly,lx };
  while (right.first != left.first) {
    if (right.first > left.first) {
      left.first++;
      left.second++;
    } else if (right.first < left.first) {
      right.first++;
      right.second--;
    }
  }
  int cx = (right.second + left.second) / 2;
  int cy = (right.first + (right.second - cx));
  visit++;
  return calculate(n, sy, sx, ly, lx, ry, rx, cy, cx);
}

int find_right_point(int n, int sy, int sx, int ly, int lx) {
  int answer = 987654321;
  int y = sy + 1;
  int x = sx + 1;
  while (y < n && x < n) {
    answer = min(answer, find_cross_point(n, sy, sx, ly, lx, y++, x++));
  }
  return answer;
}

int find_left_point(int n, int sy, int sx) {
  int answer = 987654321;
  int y = sy + 1;
  int x = sx - 1;
  while (y < n && x >= 0) {
    answer = min(answer, find_right_point(n, sy, sx, y++, x--));
  }
  return answer;
}

int solve(int n) {
  int answer = 987654321;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      answer = min(answer, find_left_point(n, i, j));
    }
  }
  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
  cout << solve(n);
  return 0;
}
