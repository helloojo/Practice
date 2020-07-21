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
//BOJ #15904
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char str[] = "UCPC";
	string s;
	bool flag = false;
	int idx = 0;
	while (cin >> s) {
		for (int i = 0; i < s.size(); i++) {
			if (str[idx] == s[i]) {
				idx++;
			}
			if (idx == 4) {
				flag = true;
				break;
			}
		}
	}
	cout << (flag ? "I love UCPC" : "I hate UCPC");
}
