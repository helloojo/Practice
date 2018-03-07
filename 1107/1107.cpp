#include <iostream>
using namespace std;
//BOJ #1107
int broken[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	int current = 100;
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		cin >> broken[i];
	}	
	return 0;
}