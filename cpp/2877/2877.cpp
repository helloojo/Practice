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
//BOJ #2877
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	string s;
	while (k>0) {
		if (k & 1) {
			s.push_back('4');
			k /= 2;
		} else {
			s.push_back('7');
			k /= 2;
			k--;
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << s[i];
	}
}
