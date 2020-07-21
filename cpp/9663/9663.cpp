#include <iostream>
using namespace std;
//BOJ #9663
int n;
bool flag_r[15];
bool flag_lurd[30];
bool flag_ldru[30];
int pos[15];
int find(int col) {
	int row;
	int ret = 0;
	for (row = 0; row < n; row++) {
		if (!(flag_r[row] || flag_lurd[col - row + 7] || flag_ldru[col + row])) {
			pos[col] = row;
			if (col == n - 1) {
				return 1;
			} else {
				flag_r[row] = true;
				flag_lurd[col - row + 7] = true;
				flag_ldru[col + row] = true;
				ret += find(col + 1);
				flag_r[row] = false;
				flag_lurd[col - row + 7] = false;
				flag_ldru[col + row] = false;
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cout << find(0);
}