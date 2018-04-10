#include <iostream>
using namespace std;
//BOJ #1937

int map[501][501];
int memo[501][501];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	return 0;
}