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
//BOJ #15873

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int num[2] = { 0 };
	int ii = 0;
	for (int i = 0; i < s.size(); i++) {
		num[ii] = num[ii] * 10 + (s[i] - '0');
		if (num[ii] > 10) {
			num[ii++] /= 10;
			i--;
		}
	}
	cout << num[0] + num[1];
}
