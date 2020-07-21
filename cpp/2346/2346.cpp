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
//BOJ #2346
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int num;
	list<pair<int, int>> l;
	for(int i = 0; i < n; i++) {
		cin >> num;
		l.push_back({ num,i + 1 });
	}
	auto cur = l.begin();
	while(!l.empty()) {
		if(cur == l.end()) {
			cur = l.begin();
		}
		int temp = cur->first - 1;
		cout << cur->second << ' ';

		cur = l.erase(cur);
		if(temp < 0) {
			temp = -temp;
			temp--;
			for(int i = 0; i < temp; i++) {
				if(cur == l.begin()) {
					cur = l.end();
				}
				cur--;
			}
		} else {
			for(int i = 0; i < temp; i++) {
				if(cur == l.end()) {
					cur = l.begin();
				}
				cur++;
				if(cur == l.end()) {
					cur = l.begin();
				}
			}
		}
	}
}