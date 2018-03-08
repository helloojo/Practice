#include <iostream>
using namespace std;
//BOJ #11066

int file[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int k;
	while(t--) {
		cin>>k;
		for(int i = 0; i<k; i++) {
			cin>>file[i];
		}

	}
	return 0;
}