#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//BOJ #2981
int num[101];

int gcd(int a, int b) {
	if(b==0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int curgcd = -1;
	int minn = 1000000001;
	int maxn = -1;
	for(int i = 0; i<n; i++) {
		cin>>num[i];
		maxn = max(maxn, num[i]);
		minn = min(minn, num[i]);
	}
	int point = maxn-minn;
	vector<int> div;
	for(int i = 2; i*i<=point; i++) {
		if(point%i==0) {
			if(point/i==i) {
				div.push_back(i);
			} else {
				div.push_back(i);
				div.push_back(point/i);
			}
		}
	}
	div.push_back(point);
	sort(div.begin(), div.end());
	for(int i = 0; i<div.size(); i++) {
		bool ok = true;
		int compare = num[0]%div[i];
		for(int j = 1; j<n; j++) {
			if(compare!=(num[j]%div[i])) {
				ok = false;
			}
		}
		if(ok) {
			cout<<div[i]<<' ';
		}
	}
	return 0;
}