#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//BOJ #1436

int main() {
  int n;
  cin >> n;
  int front = 0;
  int back = 0;
  bool f = true;
  int up = 0;
  int upmax = 0;
  int e = 0;
  for (int i = 1; i < n; i++) {
    if (f) {
      front++;
      if (front % 10 == 6) {
        int t = front;
        while (t) {
          if (t % 10 == 6) {
            up++;
            t /= 10;
          } else {
            break;
          }
        }
        e = t;
        upmax = pow(10, up);
        f = false;
        back = 0;
      }
    } else {
      back++;
      if (back == upmax) {
        up = 0;
        f = true;
        front++;
      }
    }
  }
  if (f) {
    if (front) {
      cout << front << 666;
    } else {
      cout << 666;
    }
  } else {
    if (e) {
      cout << e << 666;
    } else {
      cout << 666;
    }
    int cc = 0;
    int t = back;
    while (t) {
      t /= 10;
      cc++;
    }
    for (int i = 0; i < up - cc; i++) {
      cout << 0;
    }
    if(back)
      cout << back;
  }
  return 0;
}