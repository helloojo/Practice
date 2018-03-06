#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #1018

char map[51][51];
int n, m;
char sample[2][8][8] = {
{
{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },
{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },
{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },
{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' }
},
{
{ 'W','B','W','B','W','B','W','B' },
{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },
{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },
{ 'B','W','B','W','B','W','B','W' },
{ 'W','B','W','B','W','B','W','B' },
{ 'B','W','B','W','B','W','B','W' }
}
};

int check(int y, int x) {
	if (y + 8 > n || x + 8 > m) {
		return 987654321;
	}
	int cnt = 0;
	int ret = 987654321;
	for (int k = 0; k < 2; k++) {
		cnt = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (map[i + y][j + x] != sample[k][i][j]) {
					cnt++;
				}
			}
		}
		ret = min(cnt, ret);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int minnum = 987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			minnum = min(minnum, check(i, j));
		}
	}
	cout << minnum;
	return 0;
}