#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int arr[3002];
int memo[3002][2];	//0 ¾È¸Ô, 1 ¸Ô

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n * 3; i++) {
		cin >> arr[i];
		memo[i][0] = 987654321;
		memo[i][1] = 987654321;
	}
	memo[0][1] = arr[0];
	memo[1][1] = arr[1];
	memo[1][0] = arr[0];
	memo[2][1] = arr[2];
	memo[2][0] = arr[0];
	for (int i = 3; i < n * 3; i++) {
		memo[i][0] = min({ memo[i][0],memo[i - 2][1],memo[i - 1][1] });
		memo[i][1] = min({ memo[i][1], memo[i - 2][0] ,memo[i - 1][0] }) + arr[i];
	}
	int ret = 987654321;
	for (int i = n * 3 - 1; i >= n * 3 - 3; i--) {
		cout << memo[i][0] << ' ' << memo[i][1] << endl;
		ret = min({ memo[i][1],ret });
	}
	cout << ret;
	return 0;
}