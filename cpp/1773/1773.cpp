#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #1773
typedef long long ll;
typedef unsigned long long ull;

bool arr[2000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,c;
	cin >> n >> c;
	int num;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		int tmp = num;
		while (tmp <= c) {
			if (!arr[tmp]) {
				ret++;
				arr[tmp] = true;
			}
			tmp += num;
		}
	}
	cout << ret;
}
