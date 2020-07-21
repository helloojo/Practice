#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
//BOJ #1021
typedef long long ll;
typedef unsigned long long ull;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int num;
  deque<int> dq;
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
  }
  int answer = 0;
  for (int i = 0; i < m; i++) {
    cin >> num;
    auto pos = find(dq.begin(), dq.end(), num);
    int back = distance(pos, dq.end());
    int front = distance(dq.begin(), pos);
    if (front > back) {
      while (dq.back() != num) {
        dq.push_front(dq.back());
        dq.pop_back();
        answer++;
      }
      dq.pop_back();
      answer++;
    } else {
      while (dq.front() != num) {
        dq.push_back(dq.front());
        dq.pop_front();
        answer++;
      }
      dq.pop_front();
    }
  }
  cout << answer;
}
