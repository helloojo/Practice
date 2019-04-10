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
//BOJ #2002
typedef long long ll;
typedef unsigned long long ull;
map<string, int> m;
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		m[s] = i;
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr[i] = m[s];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				ret++;
				break;
			}
		}
	}
	cout << ret;
}
