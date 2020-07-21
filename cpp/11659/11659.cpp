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
//BOJ #11659

int n;
int num[1000001];
int psum[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		psum[i] = psum[i - 1] + num[i];
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << psum[b] - psum[a-1] << '\n';
	}
}