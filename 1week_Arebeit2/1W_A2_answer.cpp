#include <iostream>
#include <algorithm>
using namespace std;

int coin[501];
int memo[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int p, n;
	while(t--) {
		cin>>p>>n;
		p = 10000-p;
		for(int i = 1; i<=n; i++) {
			cin>>coin[i];
		}
		for(int i = 1; i<=p; i++) {
			memo[i] = 987654321;
		}
		for(int i = 1; i<=n; i++) {
			for(int j = coin[i]; j<=p; j++) {
				memo[j] = min(memo[j], memo[j-coin[i]]+1);
			}
		}
		if(memo[p]==987654321) {
			cout<<0<<'\n';
		} else {
			cout<<memo[p]<<'\n';
		}
	}
	return 0;
}