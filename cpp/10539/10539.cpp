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
//BOJ #10539
typedef long long ll;
typedef unsigned long long ull;

int a[101];
int b[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		ll x = b[i] * i;
		for (int j = 1; j < i; j++) {
			x -= a[j];
		}
		a[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
}
