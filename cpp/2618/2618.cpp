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
//BOJ #2618
typedef long long ll;
typedef unsigned long long ull;
int memo[1003][1003];
pair<int,pair<int, int>> rev[1003][1003];
pair<int, int> e[1003];
int cal(pair<int, int>& a, pair<int, int>& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, w;
	cin >> n >> w;
	e[0] = { 1,1 };
	e[1] = { n,n };
	for(int i = 2; i < w + 2; i++) {
		cin >> e[i].first >> e[i].second;
	}
	for(int i = 0; i <= w + 2; i++) {
		for(int j = 0; j <= w + 2; j++) {
			memo[i][j] = 987654321;
		}
	}
	memo[0][1] = 0;
	pair<int, pair<int, int>> ret = { 987654321,{0,0} };
	for(int i = 2; i < w + 2; i++) {
		for(int j = 0; j < i; j++) {
			if(memo[i - 1][i] > memo[i - 1][j] + cal(e[j], e[i])) {
				memo[i - 1][i] = memo[i - 1][j] + cal(e[j], e[i]);
				rev[i - 1][i].first = 2;
				rev[i - 1][i].second = { i - 1,j };
			}
			if(memo[i][j] > memo[i - 1][j] + cal(e[i - 1], e[i])) {
				memo[i][j] = memo[i - 1][j] + cal(e[i - 1], e[i]);
				rev[i][j].first = 1;
				rev[i][j].second = { i - 1,j };
			}
			if(memo[j][i] > memo[j][i - 1] + cal(e[i - 1], e[i])) {
				memo[j][i] = memo[j][i - 1] + cal(e[i - 1], e[i]);
				rev[j][i].first = 2;
				rev[j][i].second = { j,i - 1 };
			}
			if(memo[i][i - 1] > memo[j][i - 1] + cal(e[j], e[i])) {
				memo[i][i - 1] = memo[j][i - 1] + cal(e[j], e[i]);
				rev[i][i - 1].first = 1;
				rev[i][i - 1].second = { j,i - 1 };
			}
			if(i == w + 1) {
				if(ret.first > memo[i - 1][i]) {
					ret.first = memo[i - 1][i];
					ret.second = { i - 1,i };
				}
				if(ret.first > memo[i][j]) {
					ret.first = memo[i][j];
					ret.second = { i,j };
				}
				if(ret.first > memo[j][i]) {
					ret.first = memo[j][i];
					ret.second = { j,i };
				}
				if(ret.first > memo[i][i - 1]) {
					ret.first = memo[i][i - 1];
					ret.second = { i,i - 1 };
				}
			}
		}
	}
	cout << ret.first << '\n';
	pair<int, int> temp = ret.second;
	vector<int> retn;
	while(temp.first != 0 || temp.second != 0) {
		retn.push_back(rev[temp.first][temp.second].first);
		temp = rev[temp.first][temp.second].second;
	}
	for(int i = 0; i < retn.size()-1; i++) {
		cout << retn[i] << '\n';
	}
}
