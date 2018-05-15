#include <iostream>
using namespace std;
//BOJ #7569

int m, n, h;
int map[101][101][101];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin>>map[i][j][k];
			}
		}
	}
}