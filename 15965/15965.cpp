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
//BOJ #15965
typedef long long ll;
typedef unsigned long long ull;
#define SIZE 150000
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> k;
	ull prime[SIZE] = { 0 };
	for(int i = 2; i*i <= 64*SIZE; i++) {
		if(prime[i / 64] & (1ull << (i % 64))) {
			continue;
		}
		for(int j = i * i; j <= 64*SIZE; j += i) {
			prime[j / 64] |= (1ull << (j % 64));
		}
	}
	vector<int> pr;
	for(int i = 2; i <= 64*SIZE; i++) {
		if(!(prime[i / 64] & (1ull << (i % 64)))) {
			pr.push_back(i);
		}
	}
	cout << pr[k - 1];
}
