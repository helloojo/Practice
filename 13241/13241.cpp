#include <iostream>
using namespace std;
//BOJ #13241
typedef long long ll;

ll gcd(ll a, ll b) {
	if(b==0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a, b;
	cin>>a>>b;
	cout<<a*(b/gcd(a, b))<<'\n';
	return 0;
}