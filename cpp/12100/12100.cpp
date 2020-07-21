#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #12100

int map[21][21];



void copy(int dest[21][21], int src[21][21], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dest[i][j] = src[i][j];
    }
  }
}

enum {UP,DOWN,LEFT,RIGHT};

int simulate(int m[21][21], int n, int cnt) {
  if (cnt == 5) {
    int maxn = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        maxn = max(m[i][j], maxn);
      }
    }
    return maxn;
  }
  int ret = 0;
  int copy_map[21][21];
  copy(copy_map, m, n);
  for (int d = 0; d < 4; d++) {
    queue<int> q;
    switch (d) {
    case UP:
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (m[j][i]) {
            q.push(m[j][i]);
            m[j][i] = 0;
          }
        }
        int idx = 0;
        while (!q.empty()) {
          int num = q.front();
          q.pop();
          if (m[idx][i] == 0) {
            m[idx][i] = num;
          } else if (m[idx][i] == num) {
            m[idx++][i] *= 2;
          } else {
            m[++idx][i] = num;
          }
        }
      }
      break;
    case DOWN:
      for (int i = 0; i < n; i++) {
        for (int j = n-1; j >=0; j--) {
          if (m[j][i]) {
            q.push(m[j][i]);
            m[j][i] = 0;
          }
        }
        int idx = n-1;
        while (!q.empty()) {
          int num = q.front();
          q.pop();
          if (m[idx][i] == 0) {
            m[idx][i] = num;
          } else if (m[idx][i] == num) {
            m[idx--][i] *= 2;
          } else {
            m[--idx][i] = num;
          }
        }
      }
      break;
    case LEFT:
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (m[i][j]) {
            q.push(m[i][j]);
            m[i][j] = 0;
          }
        }
        int idx = 0;
        while (!q.empty()) {
          int num = q.front();
          q.pop();
          if (m[i][idx] == 0) {
            m[i][idx] = num;
          } else if (m[i][idx] == num) {
            m[i][idx++] *= 2;
          } else {
            m[i][++idx] = num;
          }
        }
      }
      break;
    case RIGHT:
      for (int i = 0; i < n; i++) {
        for (int j = n-1; j >=0; j--) {
          if (m[i][j]) {
            q.push(m[i][j]);
            m[i][j] = 0;
          }
        }
        int idx = n-1;
        while (!q.empty()) {
          int num = q.front();
          q.pop();
          if (m[i][idx] == 0) {
            m[i][idx] = num;
          } else if (m[i][idx] == num) {
            m[i][idx--] *= 2;
          } else {
            m[i][--idx] = num;
          }
        }
      }
      break;
    }
    ret = max(ret, simulate(m, n, cnt + 1));
    copy(m, copy_map, n);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }
  cout << simulate(map, n, 0);
}
