#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// BOJ #6064
typedef long long ll;
typedef unsigned long long ull;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    int sum = 0;
    bool find = false;
    int l = lcm(m, n);
    for(int i=x;i<=l;i+=m) {
        if(i%n==0) {
            if(y==n) {
              find = true;
              sum = i;
              break;
            }
        } else {
          if (i % n == y) {
            find = true;
            sum = i;
            break;
          }
        }
    }
    cout << (find ? sum : -1) << '\n';
  }
}