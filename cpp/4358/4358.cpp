#include <iostream>
#include <string>
#include <iomanip>
#include <map>
using namespace std;
map<string, int> m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  int cnt = 0;
  while (getline(cin, s)) {
    cnt++;
    m[s]++;
  }
  cout << fixed << setprecision(4);
  for (auto& p : m) {
    double ratio = (static_cast<double>(p.second) / cnt)*100;
    cout << p.first << ' ' << ratio << '\n';
  }
}