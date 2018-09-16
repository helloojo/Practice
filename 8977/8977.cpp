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
//BOJ #8977
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k, b;
	cin >> n >> k >> b;
	int arr[101];
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	for(int i = 0, j = b % n; i < k; i++, j=(j+1)%(n+1)) {
		if(j == 0) {
			j = 1;
		}
		sum += arr[j];
	}
	cout << sum;
}
