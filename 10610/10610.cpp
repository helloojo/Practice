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
//BOJ #10610
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string n;
	cin >> n;
	int temp = 0;
	bool can = false;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '0') {
			can = true;
		}
		temp += n[i] - '0';
	}
	if (temp % 3 == 0 && can) {
		sort(n.begin(), n.end(), [](char a, char b) {
			return a > b;
		});
		cout << n;
	} else {
		cout << -1;
	}
}
