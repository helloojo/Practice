#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #9465
typedef long long ll;
ll map[2][100001];
ll memo[3][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int n;
	while(t--) {
		cin>>n;
		for(int i = 0; i<2; i++) {
			for(int j = 1; j<=n; j++) {
				cin>>map[i][j];
			}
		}
		for(int i = 1; i<=n; i++) {
			memo[0][i] = max(memo[2][i-1], memo[1][i-1])+map[0][i];
			memo[1][i] = max(memo[2][i-1], memo[0][i-1])+map[1][i];
			memo[2][i] = max({memo[0][i-1],memo[1][i-1],memo[2][i-1]});
		}
		cout<<max({memo[0][n],memo[1][n],memo[2][n]})<<'\n';
	}
	/*
	3가지 케이스
	memo[n][i] -> n위치에 스티커를 고른거의 최대값 (2는 안고른거)
	위에 스티커를 골랐을때,밑에 스티커를 골랐을때, 안골랐을때
	위 : 왼쪽에 있는 건 못고르고 왼쪽아래나 안고른거+자신
	아래 : 왼쪽위,안고른거+자신
	안 : 왼쪽위,아래,안고른거 중에 최대값
	*/
	return 0;
}