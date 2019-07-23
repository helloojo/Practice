#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #1788
typedef long long ll;
typedef unsigned long long ull;
int fibo[2000010];
#define N 1000000
#define DIV 1000000000
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fibo[0 + N] = 0;
    fibo[1 + N] = 1;
    fibo[-1 + N] = 1;
    for (int i = 2; i <= N; i++) {
        fibo[i + N] = (fibo[i - 1 + N] % DIV + fibo[i - 2 + N] % DIV) % DIV;
    }
    for (int i = -2; i >= -N; i--) {
        fibo[i + N] = (fibo[i + 2 + N] % DIV - fibo[i + 1 + N] % DIV) % DIV;
    }
    int n;
    cin >> n;
    int f = fibo[n + N];
    if (f == 0) {
        cout << 0 << '\n';
        cout << 0 << '\n';
    } else if (f > 0) {
        cout << 1 << '\n';
        cout << f << '\n';
    } else {
        cout << -1 << '\n';
        cout << -f << '\n';
    }
}
