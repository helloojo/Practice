#include <iostream>
#include <cmath>
using namespace std;
//BOJ #1011
typedef unsigned long long ull;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int x, y;
	int ret = 0;
	while(t--) {
		cin>>x>>y;
		ret = 0;
		ull dist = y-x;
		ull i = 1;
		for(; i*i<dist; i++);
		if(i*i!=dist) {
			i--;
		}
		ret += (2*i-1);
		dist -= (i*i);
		double j = (double)dist/i;
		ret += ceil(j);
		cout<<ret<<'\n';
	}
	return 0;
}