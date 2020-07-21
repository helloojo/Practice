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
//BOJ #2991
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int arr[3];
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 3; i++) {
		int aa = arr[i] % (a + b);
		int bb = arr[i] % (c + d);
		int ret = 0;
		if (aa <= a && aa != 0) {
			ret++;
		}
		if (bb <= c && bb != 0) {
			ret++;
		}
		cout << ret << '\n';
	}


}
