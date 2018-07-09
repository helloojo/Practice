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
//BOJ #9421

bool visited[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	bool isprime[1000001];
	for (int i = 0; i < 1000001; i++) {
		isprime[i] = true;
	}
	for (int i = 2; i*i < 1000001; i++) {
		for (int j = i * i; j < 1000001; j += i) {
			isprime[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			memset(visited, 0, sizeof(visited));
			int temp = i;
			bool can = true;
			while (temp != 1) {
				int t = temp;
				temp = 0;
				while (t) {
					temp += (t % 10)*(t % 10);
					t /= 10;
				}
				if (visited[temp]) {
					can = false;
					break;
				}
				visited[temp] = true;
			}
			if (can) {
				cout << i << '\n';
			}
		}
	}
}
