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
//BOJ #1744
int num[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	int ret = 0;
	int i = n - 1;
	for (; num[i] > 0; i--) {
		if (i-1>=0 && num[i - 1] > 1) {
			ret += num[i] * num[i - 1];
			i--;
		} else {
			ret += num[i];
		}
	}
	for (int j = 0; j <= i; j++) {
		if (j+1<=i && num[j + 1] <= 0) {
			ret += num[j] * num[j + 1];
			j++;
		} else {
			ret += num[j];
		}
	}
	cout << ret;
}
