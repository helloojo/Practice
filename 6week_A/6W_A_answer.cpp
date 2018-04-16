#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int memo[1005][1005];	//memo[i][j] -> pos[i]위치에 인하 pos[j]위치에 비룡 최단거리
int pos[1005];
int n, m;

/*
우선 다이나믹 배열의 정의를 memo[i, j] = i번째에 인하가, j번째에 비룡이 있을 때 최단거리.라고 두자.
이때 i - 1번째 사건은 무조건 자기 전에 거쳐야함으로 우리가 봐야할 것은
memo[i - 1][j]
memo[j][i - 1] 이다.

memo[i - 1][j]
memo[i][j] = memo[i - 1][j] + i - 1번째 위치에서 i번째 위치까지 거리. //인하 이동시켰을 때
memo[i - 1][i] = memo[i - 1][j] + j번재 위치에서 i번째 위치까지의 거리. //비룡 이동시켰을 때

memo[j][i - 1]
memo[i][i - 1] = memo[j][i - 1] + j번째 위치에서 i번재 위치까지 거리.   //인하 이동했을 때
memo[j][i] = memo[j][i - 1] + i - 1번째 위치에서 i번째 위치까지의 거리. //비룡 이동했을 때
인하의 초기위치 0을 위치0, 비룡의 초기위치 n을 위치1, 그뒤로 수리집1을 위치2 수리집2를 위치3
그리고 배열은 모두 무한으로 초기화 해두며, memo[0][1], 즉 초기상태는 0으로 초기화 한다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	int ret = 0;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		
		for (int i = 2; i < m + 2; i++) {
			cin >> pos[i];
		}
		for (int i = 0; i < m + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				memo[i][j] = 987654321;
			}
		}
		pos[0] = 0;
		pos[1] = n;

		memo[0][1] = 0;
		ret = 987654321;
		for (int i = 2; i < m + 2; i++) {
			for (int j = 0; j < i; j++) {
				memo[i][i - 1] = min(memo[i][i - 1], memo[j][i - 1] + abs(pos[j] - pos[i]));
				memo[j][i] = min(memo[j][i], memo[j][i - 1] + abs(pos[i - 1] - pos[i]));
				if (i == m + 1) {
					ret = min({ ret, memo[j][i],memo[i][i - 1] });
				}
			}
			for (int j = 0; j < i; j++) {
				memo[i][j] = min(memo[i][j], memo[i - 1][j] + abs(pos[i - 1] - pos[i]));
				memo[i - 1][i] = min(memo[i - 1][i], memo[i - 1][j] + abs(pos[j] - pos[i]));
				if (i == m + 1) {
					ret = min({ ret,memo[i][j],memo[i - 1][i] });
				}
			}
		}
		cout << ret << '\n';
	}
	return 0;
}