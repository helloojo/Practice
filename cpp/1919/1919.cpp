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
//BOJ #1919
typedef long long ll;
typedef unsigned long long ull;

int acnt[26];
int bcnt[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) {
		acnt[a[i] - 'a']++;
	}
	for (int i = 0; i < b.size(); i++) {
		bcnt[b[i] - 'a']++;
	}
	int ret = 0;
	for (int i = 0; i < 26; i++) {
		ret += (abs(acnt[i] - bcnt[i]));
	}
	cout << ret;
}