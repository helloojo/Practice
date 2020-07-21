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
//BOJ #1963

bool isprime[10001];
int pos[10] = { 0,1,2,3,4,5,6,7,8,9 };
bool visited[10001];
int s, d;
queue<pair<int, int>> q;
int bfs(int n) {
	q.push({ n,0 });
	visited[n] = true;
	int ret = 987654321;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int here = p.first;
		int cnt = p.second;
		if (here == d) {
			ret = min(ret, cnt);
		}
		for (int i = 0; i < 10; i++) {
			string temp = to_string(here);
			for (int j = 0; j < 4; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				char tmp = temp[j];
				temp[j] = pos[i] + '0';
				int next = stoi(temp);
				if (isprime[next]) {
					temp[j] = tmp;
					continue;
				}
				if (visited[next]) {
					temp[j] = tmp;
					continue;
				}
				visited[next] = true;
				q.push({ next, cnt + 1 });
				temp[j] = tmp;
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 2; i*i < 10001; i++) {
		for (int j = i * i; j < 10001; j += i) {
			isprime[j] = true;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		memset(visited, 0, sizeof(visited));
		cin >> s >> d;
		int ret = bfs(s);
		if (ret == 987654321) {
			cout << "Impossible\n";
		} else {
			cout << ret << '\n';
		}
	}

}
