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
//BOJ #9205

int store[100][2];
int n;
int sy, sx, dy, dx;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> sx >> sy;
		for (int i = 0; i < n; i++) {
			cin >> store[i][0] >> store[i][1];
		}
		cin >> dx >> dy;
		if (1) {
			cout << "happy\n";
		} else {
			cout << "sad\n";
		}
	}
}
