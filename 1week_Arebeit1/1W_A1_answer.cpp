#include <iostream>
using namespace std;

int coin[15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int p, n;
	int ret = 0;
	while(t--) {
		cin>>p>>n;
		ret = 0;
		p = 10000-p;
		for(int i = 1; i<=n; i++) {
			cin>>coin[i];
		}
		if(!(p%coin[1])) {
			while(p) {
				ret += (p/coin[n]);
				p %= coin[n];
				n--;
			}
		}
		cout<<ret<<'\n';
	}
	return 0;
}