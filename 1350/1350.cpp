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
//BOJ #1350
typedef long long ll;
typedef unsigned long long ull;
int arr[1000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ret = 0;
	int clu;
	cin >> clu;
	for (int i = 0; i < n; i++) {
		ret += (arr[i] / clu)*clu;
		arr[i] %= clu;
		if (arr[i]) {
			ret += clu;
		}
	}
	cout << ret;
}
