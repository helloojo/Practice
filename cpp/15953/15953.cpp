#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #15953
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int first[6] = { 1,3,6,10,15,21 };
	int fp[] = { 5000000,3000000,2000000,500000,300000,100000,0 };
	int second[5] = { 1,3,7,15,31 };
	int sp[] = { 5120000,2560000,1280000,640000,320000,0 };

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a != 0) {
			a = lower_bound(first, first + 6, a) - first;
			a = fp[a];
		}
		if (b != 0) {
			b = lower_bound(second, second + 5, b) - second;
			b = sp[b];
		}
		cout << a + b << '\n';
	}
}
