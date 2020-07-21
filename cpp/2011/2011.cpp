#include <iostream>
#include <string>
using namespace std;
//BOJ #2011
const long long MOD = 1000000;
long long memo[5002];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int len = s.size();
	memo[0] = 1;
	bool can = true;
	for (int i = 1; i <= len; i++) {
		if (s[i - 1]<'0' && s[i - 1]>'9') {
			can = false;
			break;
		}
		if (s[i - 1] == '0') {
			if (i == 1) {
				can = false;
				break;
			} else {
				if (s[i - 2] == '1' || s[i - 2] == '2') {
					memo[i] = (memo[i] % MOD + memo[i - 2] % MOD) % MOD;
				} else {
					can = false;
					break;
				}
			}
		} else {
			if (i != 1) {
				if (s[i - 2] == '1') {
					memo[i] = (memo[i] % MOD + memo[i - 2] % MOD) % MOD;
				} else if (s[i - 2] == '2') {
					if (s[i - 1] >= '1' && s[i - 1] <= '6') {
						memo[i] = (memo[i] % MOD + memo[i - 2] % MOD) % MOD;
					}
				}
			}
			memo[i] = (memo[i] % MOD + memo[i - 1] % MOD) % MOD;
		}
	}
	if (can) {
		cout << memo[len];
	} else {
		cout << 0;
	}

	return 0;
}