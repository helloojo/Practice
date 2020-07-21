#include <iostream>
#include <vector>

using namespace std;
//BOJ #9020

vector<int> prime;

void Eratos() {
	bool isPrime[10001];
	for(int i=2;i<=10000;i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i*i <= 10000; i++) {
		if (!isPrime[i]) continue;
		for (int j = i * i; j <= 10000; j += i) {
			isPrime[j] = false;
		}
	}
	for (int i = 2; i <= 10000; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	Eratos();
	int last = prime.size();
	int start = 0;
	int mid = 0;
	int differ = 987654321;
	pair<int, int> ret;
	while (t--) {
		int n;
		cin >> n;
		differ = 987654321;

		cout << ret.first << ' ' << ret.second << '\n';
	}
	return 0;
}