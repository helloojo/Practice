#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #2206

struct Status {
	int x;
	int y;
	bool hit;
	int dis;
	Status(int _x, int _y, bool _hit,int _dis) {
		x = _x;
		y = _y;
		hit = _hit;
		dis = _dis;
	}
};

int n, m;
char map[1001][1001];
int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<Status> q;

int BFS() {
	int ret = 987654321;
	q.push(Status(0, 0, false,1));
	map[0][0] = '-1';
	while(!q.empty()) {
		auto s = q.front();
		q.pop();
		if(s.x==m-1&&s.y==n-1) {
			ret = min(ret, s.dis);
		}
		for(int i = 0; i<4; i++) {
			int nx = s.x+pos[i][0];
			int ny = s.y+pos[i][1];
			if(nx<0||ny<0||nx>=m||ny>=n) {
				continue;
			}
			if((map[ny][nx]=='1' && s.hit)||map[ny][nx]=='-1') {
				continue;
			}
			if(map[ny][nx]=='1') {
				q.push(Status(nx, ny, true, s.dis+1));
			} else {
				q.push(Status(nx, ny, s.hit, s.dis+1));
			}
			map[ny][nx] = '-1';
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i = 0; i<n; i++) {
		cin>>map[i];
	}
	int ans = BFS();
	if(ans==987654321) {
		cout<<-1;
	} else {
		cout<<ans;
	}

	return 0;
}