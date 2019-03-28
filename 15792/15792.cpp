#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #15792
typedef long long ll;
typedef unsigned long long ull;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	scanf("%d %d", &a, &b);
	int p = a / b;
	int q = a % b;
	printf("%d.", p);
	int cnt = 0;
	while (q) {
		p = q * 10;
		printf("%d", p / b);
		q = p % b;
		cnt++;
		if (cnt > 1000) {
			break;
		}
	}
}
