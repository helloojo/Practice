#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    while (n--) {
      cin >> a >> b;
      m[b]++;
    }
    int ret = 1;
    for (auto& p : m) {
      ret *= (p.second + 1);
    }
    cout << --ret << '\n';
    m.clear();
  }
}