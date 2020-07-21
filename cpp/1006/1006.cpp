#include <iostream>
#include <queue>
using namespace std;

int pos[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int s[2][10000];
bool visited[2][10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, w;
		cin >> n >> w;
		for (int i = 0; i < 2; i++) {
			memset(visited[i], 0, sizeof(bool) * 10000);
			for (int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
		}
	}
	return 0;
}