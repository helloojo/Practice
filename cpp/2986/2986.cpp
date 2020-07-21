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
//BOJ #2986

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	bool prime = true;
	for (int i = 2; i*i <= n; i++) {
		if (n&i == 0) {
			prime = false;
		}
	}
	if (prime) {
		cnt = n - 1;
	} else {
		for (int i = n / 2 + 1; i >= 1; i--) {
			if (n%i == 0) {
				cnt = n - i;
				break;
			}
		}
	}
	cout << cnt;
}