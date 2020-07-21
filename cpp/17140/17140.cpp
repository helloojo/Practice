#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #17140
typedef long long ll;
typedef unsigned long long ull;
int r, c, k;
int map[101][101];
int height[101];
int width[101];
pair<int, int> num[101];

static int max(int a, int b) {
	return (a > b ? a : b);
}

void init() {
	for (int i = 0; i <= 100; i++) {
		num[i].first = 0;
		num[i].second = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> k;
	r--; c--;
	int w = 3;
	int h = 3;
	int i, j, idx;
	for (i = 0; i < 3; i++) {
		height[i] = 3;
		for (j = 0; j < 3; j++) {
			cin >> map[i][j];
			width[j] = 3;
		}
	}
	if (map[r][c] == k) {
		cout << 0;
		return 0;
	}
	int time;
	for (time = 1; time <= 100; time++) {
		if (w > h) {
			int temph = 0;
			for (i = 0; i < 100; i++) {
				width[i] = 0;
			}
			for (i = 0; i < w; i++) {
				int maxn = 0;
				init();
				for (j = 0; j < height[i]; j++) {
					if (map[j][i]) {
						num[map[j][i]].first++;
						maxn = max(map[j][i], maxn);
					}
				}
				sort(num + 1, num + 1 + maxn);
				for (j = 0; j < 100; j++) {
					map[j][i] = 0;
				}
				for (idx = 1, j = 0; idx <= maxn; idx++) {
					if (num[idx].first) {
						width[j] = max(width[j], i + 1);
						map[j++][i] = num[idx].second;
						width[j] = max(width[j], i + 1);
						map[j++][i] = num[idx].first;
					}
				}
				height[i] = j;
				temph = max(temph, j);
			}
			h = temph;
		} else {
			int tempw = 0;
			for (i = 0; i < 100; i++) {
				height[i] = 0;
			}
			for (i = 0; i < h; i++) {
				int maxn = 0;
				init();
				for (j = 0; j < width[i]; j++) {
					if (map[i][j]) {
						num[map[i][j]].first++;
						maxn = max(map[i][j], maxn);
					}
				}
				sort(num + 1, num + 1 + maxn);
				for (j = 0; j < 100; j++) {
					map[i][j] = 0;
				}
				for (idx = 1, j = 0; idx <= maxn; idx++) {
					if (num[idx].first) {
						height[j] = max(height[j], i + 1);
						map[i][j++] = num[idx].second;
						height[j] = max(height[j], i + 1);
						map[i][j++] = num[idx].first;
					}
				}
				width[i] = j;
				tempw = max(tempw, j);
			}
			w = tempw;
		}
		if (map[r][c] == k) {
			break;
		}
	}
	cout << (time == 101 ? -1 : time);
}
