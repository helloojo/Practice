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
//BOJ #1644

bool isprime[4000001];
vector<int> prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 2; i*i <= n; i++) {
		for (int j = i * i; j <= n; j += i) {
			isprime[j] = true;
		}
	}
	int size = 0;
	for (int i = 2; i <= n; i++) {
		if (!isprime[i]) {
			prime.push_back(i);
			size++;
		}
	}
	int ret = 0;
	for (int i = 0; i < size; i++) {
		int sum = 0;
		for (int j = i; sum < n && j<size; j++) {
			sum += prime[j];
			if (sum == n) {
				ret++;
			}
		}
	}
	cout << ret;
}
