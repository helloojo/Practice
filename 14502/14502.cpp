#include <iostream>
using namespace std;
//BOJ #14502

int map[8][8];
bool visited[8][8];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	pair<int,int> wall[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j] == 0) {
					wall[i].first = j;
					wall[i].second = k;
					map[i][j] = 1;
				}
			}
		}
	}
}