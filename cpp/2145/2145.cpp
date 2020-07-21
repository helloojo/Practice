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
//BOJ #2145

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	while (n != 0) {
		while (n >= 10) {
			int c = 0;
			while (n != 0) {
				c += n % 10;
				n /= 10;
			}
			n = c;
		}
		cout << n << '\n';
		cin >> n;
	}
}
