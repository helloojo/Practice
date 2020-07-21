#include <iostream>
#include <deque>
using namespace std;

bool square[9][10];
bool row[9][10];
bool col[9][10];
int map[9][3][3];
int zerocnt[9];
int unseen[10];
deque<pair<int, int>> zero;

bool sudoku(int idx = 0) {
  if (idx == zero.size()) {
    return true;
  }
  int y = zero[idx].first;
  int x = zero[idx].second;
  int l = (y / 3) * 3 + (x / 3);
  for (int i = 1; i <= 9; i++) {
    if (square[l][i] || row[y][i] || col[x][i]) {
      continue;
    }
    map[l][y % 3][x % 3] = i;

    square[l][i] = row[y][i] = col[x][i] = true;
    if (sudoku(idx + 1)) {
      return true;
    }
    map[l][y % 3][x % 3] = 0;

    square[l][i] = row[y][i] = col[x][i] = false;
  }
  return false;
}

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int num;
      cin >> num;
      int l = (i / 3) * 3 + (j / 3);
      map[l][i % 3][j % 3] = num;
      if (num == 0) {
        zerocnt[l]++;
      }
    }
  }
  //remove one zero
  int us = 0;
  for (int i = 0; i < 9; i++) {
    us++;
    int zx, zy;
    if (zerocnt[i] == 1) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          unseen[map[i][j][k]] = us;
          if (map[i][j][k] == 0) {
            zx = k;
            zy = j;
          }
        }
      }
      for (int j = 1; j <= 9; j++) {
        if (unseen[j] != us) {
          map[i][zy][zx] = j;
          break;
        }
      }
    }
  }//remove one zero

  //cal square, save zero
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        int num = map[i][j][k];
        square[i][num] = true;
      }
    }
  }//cal square

  //cal row, col, save zero
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int l = (i / 3) * 3 + (j / 3);
      int num = map[l][i % 3][j % 3];
      row[i][num] = true;
      col[j][num] = true;
      if (num == 0) {
        zero.push_back({ i,j });
      }
    }
  }//cal row, col, save zero

  int size = zero.size();
  for (int i = 0; i < size; i++) {
    if (sudoku()) {
      break;
    }
    zero.push_back(zero.front());
    zero.pop_front();
  }

  //print
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int l = (i / 3) * 3 + (j / 3);
      cout << map[l][i % 3][j % 3] << ' ';
    }
    cout << '\n';
  }
}