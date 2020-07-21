#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//BOJ #1004

struct Point {
	int x;
	int y;
};

struct Planet {
	int x;
	int y;
	int r;
};

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	Point start;
	Point dest;
	while (t--) {
		cin >> start.x >> start.y;
		cin >> dest.x >> dest.y;
		int n;
		int ret = 0;
		cin >> n;
		Planet p;
		for (int i = 0; i < n; i++) {
			cin >> p.x >> p.y >> p.r;
			ll sd = pow(p.x - start.x, 2) + pow(p.y - start.y, 2);
			ll dd = pow(p.x - dest.x, 2) + pow(p.y - dest.y, 2);
			//시작점과 도착점이 행성계에 안과 밖에 있는걸 구함
			if ((p.r*p.r - sd)*(p.r*p.r - dd) < 0) {
				ret++;
			}
		}
		cout << ret << '\n';
	}
	return 0;
}