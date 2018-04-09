#include <iostream>
#include <queue>
using namespace std;
//BOJ #10216

int map[5001][5001];
queue<pair<int, int>> q;
int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void BFS(int x, int y) {
	q.push(make_pair(x, y));
	map[y][x] = 0;
	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		for(int i = 0; i<4; i++) {
			int nx = p.first+pos[i][0];
			int ny = p.second+pos[i][1];
			if(nx<0||ny<0||nx>5000||ny>5000) {
				continue;
			}
			if(map[ny][nx]==0) {
				continue;
			}
			map[ny][nx] = 0;
			q.push(make_pair(nx, ny));
		}
	}
}

pair<int, int> coord[3000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int n;
	int x, y, r;
	while(t--) {
		cin>>n;
		for(int i = 0; i<5001; i++) {
			for(int j = 0; j<5001; j++) {
				map[i][j] = 0;
			}
		}
		for(int i = 0; i<n; i++) {
			cin>>coord[i].first>>coord[i].second>>r;
			x = coord[i].first;
			y = coord[i].second;
			map[y][x] = 1;
			for(int j = 0; j<=r; j++) {
				if(x+j<=5000) {
					map[y][x+j] = 1;
				}
				if(x-j>=0) {
					map[y][x-j] = 1;
				}
				if(y+j<=5000) {
					map[y+j][x] = 1;
				}
				if(y-j>=0) {
					map[y-j][x] = 1;
				}
			}
		}
		int ret = 0;

		for(int i = 0; i<n; i++) {
			x = coord[i].first;
			y = coord[i].second;
			if(map[y][x]==1) {
				BFS(x, y);
				ret++;
			}
		}
		
		cout<<ret<<'\n';
	}

	return 0;
}