#include <iostream>
using namespace std;

int state[4][8];
int rotated[4];
int rotate_idx;
const int LEFT = 6;
const int RIGHT = 2;
void rotate(int num, int type) {
  if (rotated[num] == rotate_idx) {
    return;
  }
  rotated[num] = rotate_idx;
  int l = num - 1;
  int r = num + 1;
  if (l >= 0) {
    if (state[l][RIGHT] != state[num][LEFT]) {
      rotate(l, -type);
    }
  }
  if (r < 4) {
    if (state[r][LEFT] != state[num][RIGHT]) {
      rotate(r, -type);
    }
  }
  if (type == 1) {
    int tmp = state[num][7];
    for (int i = 7; i > 0; i--) {
      state[num][i] = state[num][i - 1];
    }
    state[num][0] = tmp;
  } else {
    int tmp = state[num][0];
    for (int i = 0; i < 7; i++) {
      state[num][i] = state[num][i + 1];
    }
    state[num][7] = tmp;
  }
}

int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      scanf("%1d", &state[i][j]);
    }
  }
  int k;
  cin >> k;
  while (k--) {
    int a, b;
    cin >> a >> b;
    a--;
    rotate_idx++;
    rotate(a, b);
  }
  int ret = 0;
  int tmp = 1;
  for (int i = 0; i < 4; i++) {
    if (state[i][0] == 1) {
      ret += tmp;
    }
    tmp *= 2;
  }
  cout << ret;
}