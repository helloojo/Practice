#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
queue<pair<int, int>> q;
int BFS(int y, int x) {
	map[y][x] = 0;

}

int main() {
	int a, b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	int src, dest;
	cin >> src >> dest;
	
	return 0;
}