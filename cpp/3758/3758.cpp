#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #3758
typedef long long ll;
typedef unsigned long long ull;
struct team {
	int score[101] = { 0 };
	int sum = 0;
	int id;
	int last = 0;
	int cnt = 0;
	void update(int num, int sc, int ti) {
		cnt++;
		last = ti;
		if(score[num] >= sc) {
			return;
		}
		if(score[num] == 0) {
			sum += sc;
		} else {
			sum += (sc - score[num]);
		}
		score[num] = sc;
	}
} arr[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		memset(arr, 0, sizeof(arr));
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		for(int i = 1; i <= n; i++) {
			arr[i].id = i;
		}
		int i, j, s;
		int tt = 0;
		while(m--) {
			cin >> i >> j >> s;
			tt++;
			arr[i].update(j, s, tt);
		}
		sort(arr + 1, arr + 1 + n, [](team& a, team& b) {
			if(a.sum > b.sum) {
				return true;
			} else if(a.sum == b.sum) {
				if(a.cnt < b.cnt) {
					return true;
				} else if(a.cnt == b.cnt) {
					return a.last < b.last;
				}
			}
			return false;
		});
		for(int i = 1; i <= n; i++) {
			if(arr[i].id == t) {
				cout << i << '\n';
				break;
			}
		}
	}
}
