#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> lq;
priority_queue<int, vector<int>, greater<int>> gq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int num;

  for (int i = 0; i < n; i++) {
    cin >> num;

    if (lq.size() == gq.size()) {
      if (lq.size() == 0 && gq.size() == 0) {
        lq.push(num);
      } else {
        if (gq.top() < num) {
          lq.push(gq.top());
          gq.pop();
          gq.push(num);
        } else {
          lq.push(num);
        }
      }
    } else if (lq.size() > gq.size()) {
      if (lq.top() > num) {
        gq.push(lq.top());
        lq.pop();
        lq.push(num);
      } else {
        gq.push(num);
      }
    }
    cout << lq.top() << "\n";
  }

  return 0;
}
