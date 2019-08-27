#include <iostream>
using namespace std;
pair<int, int> st[1000001];
int pos = -1;
int ret[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    while (pos != -1 && st[pos].first < num) {
      ret[st[pos].second] = num;
      --pos;
    }
    st[++pos] = { num,i };
  }
  for (int i = 0; i < n; i++) {
    cout << (ret[i] ? ret[i] : -1) << ' ';
  }
}