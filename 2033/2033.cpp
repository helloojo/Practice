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
//BOJ #2033

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int gijun = 10;
	while (gijun <= n) {
		
		if (n%gijun >= gijun / 2) {
			n = n + (gijun - n % gijun);
		} else {
			n = n - n % gijun;
		}
		gijun *= 10;
	}
	cout << n;
}
