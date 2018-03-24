#include <iostream>
using namespace std;
//BOJ #11670
int num[2501][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i][0] >> num[i][1];
	}
	return 0;
}