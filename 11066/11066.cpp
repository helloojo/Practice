#include <iostream>
using namespace std;
//BOJ #11066

int file[501];
int memo[501][501];

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
		for(int i = 0; i<k; i++) {
			for(int j = 0; j<k; j++) {

			}
		}
		//쓴다, 안쓴다, memo해야할것 쓰거나 안쓴거 최소비용
		//m(i,j) -> 파일이 
	}
	return 0;
}