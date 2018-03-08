#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//BOJ #9252

int memo[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin>>a>>b;
	int as = a.size();
	int bs = b.size();
	for(int i = 1; i<=as; i++) {
		for(int j = 1; j<=bs; j++) {
			if(a[i-1]==b[j-1]) {
				memo[i][j] = memo[i-1][j-1]+1;
			} else {
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
			}
		}
	}
	string ret = "";
	for(int i = as, j = bs; i!=0 && j!=0;) {
		if(a[i-1]==b[j-1]) {
			ret += a[i-1];
			i--; j--;
		} else {
			if(memo[i-1][j]>memo[i][j-1]) {
				i--;
			} else {
				j--;
			}
		}
	}
	reverse(ret.begin(), ret.end());
	cout<<memo[as][bs]<<'\n'<<ret;
	return 0;
}