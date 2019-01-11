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
//BOJ #2225

long long memo[201][201];		//memo[i][j] -> i�� j�� ���� ����� �ִ� ����� ��

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 201; i++) {
		memo[0][i] = 1;
	}
	for (int i = 1; i <= n; i++) {	//����
		for (int j = 1; j <= k; j++) { //��� ����
			for (int p = 0; p <= i; p++) {		//p -> ����� ���� 0~i
				memo[i][j] = (memo[i][j] % 1000000000 + memo[i - p][j - 1] % 1000000000) % 1000000000;
			}
		}
	}
	cout << memo[n][k] % 1000000000;
}
