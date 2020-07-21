#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//BOJ #1958

int memo[101][101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b, c;
	cin>>a>>b>>c;
	int as = a.size();
	int bs = b.size();
	int cs = c.size();

	for(int i = 1; i<=as; i++) {
		for(int j = 1; j<=bs; j++) {
			for(int k = 1; k<=cs; k++) {
				if(a[i-1]==b[j-1] && b[j-1]==c[k-1]) {
					memo[i][j][k] = memo[i-1][j-1][k-1]+1;
				} else {
					memo[i][j][k] = max({memo[i-1][j][k],memo[i-1][j-1][k],memo[i][j-1][k],memo[i][j-1][k-1],memo[i][j][k-1],memo[i-1][j][k-1]});
				}
			}
		}
	}
	cout<<memo[as][bs][cs];
	return 0;
}