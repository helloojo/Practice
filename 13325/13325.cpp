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
//BOJ #13325
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, l;
	cin >> n >> l;
	priority_queue<pair<int, int>> pq;
	int num;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push({ -num,i });
		bool flag = true;
		while (flag) {
			if (pq.top().second <= i - l) {
				pq.pop();
			} else {
				flag = false;
			}
		}
		cout << -pq.top().first << ' ';
	}
}
