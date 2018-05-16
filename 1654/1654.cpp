#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #1654
int lan[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, n;
	int high = 0;
	int low = 0;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		high = max(high, lan[i]);
	}
}