#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #15917

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	unsigned int a;
	for (int i = 0; i < q; i++) {
		cin >> a;
		int cnt = 0;
		for (int i = 0; i < 32; i++) {
			if (a & (1u << i)) {
				cnt++;
			}
		}
		cout << (cnt == 1) << '\n';
	}
}
