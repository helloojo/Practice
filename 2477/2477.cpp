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
//BOJ #2477
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	vector<pair<int, int>> d;
	int a, b;
	pair<int, int> maxw = { 0,0 }, maxh = { 0,0 };
	int minw = 0, minh = 0;
	for(int i = 0; i < 6; i++) {
		cin >> a >> b;
		d.push_back({ a,b });
		switch(a) {
		case 1:
		case 2:
			if(maxw.second < b) {
				maxw = { a,b };
			}
			break;
		case 3:
		case 4:
			if(maxh.second < b) {
				maxh = { a,b };
			}
			break;
		}
	}
	for(int i = 0; i < 6; i++) {
		int next = (i + 1) % 6;
		int prev = (i - 1 < 0 ? 5 : i - 1);
		switch(d[i].first) {
		case 1:
		case 2:
			if(d[prev].first != maxh.first && d[next].first != maxh.first) {
				minw = d[i].second;
			}
			break;
		case 3:
		case 4:
			if(d[prev].first != maxw.first&& d[next].first!=maxw.first) {
				minh = d[i].second;
			}
			break;
		}
	}
	cout << k * (maxw.second*maxh.second - minw * minh);
}
