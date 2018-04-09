#include <iostream>
#include <vector>
using namespace std;
//BOJ #1963
//³ªÁß¿¡
vector<int> prime;

void eratos() {
	bool isprime[10001];
	for (int i = 2; i <= 10001; i++) {
		isprime[i] = true;
	}
	for (int i = 2; i*i <= 10001; i++) {
		for (int j = i * i; j <= 10001; j *= i) {
			isprime[j] = false;
		}
	}
	for (int i = 1000; i < 10000; i++) {
		if (isprime[i]) {
			prime.push_back(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(Nint);
	eratos();
	int t;
	cin >> t;
	int src, dest;
	while (t--) {
		cin >> src >> dest;
	}
	return 0;
}