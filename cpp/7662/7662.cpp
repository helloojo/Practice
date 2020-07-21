#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
//BOJ #7662
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		char c;
		int n;
		multiset<int> q;
		auto del = q.begin();
		while(k--) {
			cin >> c >> n;
			switch(c) {
			case 'I':
				q.insert(n);
				break;
			case 'D':
				if(!q.empty()) {
					switch(n) {
					case 1:
						del = --q.end();
						q.erase(del);
						break;
					case -1:
						del = q.begin();
						q.erase(del);
						break;
					}
				}
				break;
			}
		}
		if(q.empty()) {
			cout << "EMPTY\n";
		} else {
			cout << *(--q.end()) << ' ' << *(q.begin()) << '\n';
		}
	}
}
