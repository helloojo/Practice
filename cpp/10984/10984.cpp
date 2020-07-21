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
//BOJ #10984
typedef long long ll;
typedef unsigned long long ull;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int c;
		double g;
		int sum = 0;
		double gpa = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %lf", &c, &g);
			sum += c;
			gpa += (g*c);
		}
		gpa /= sum;
		printf("%d %.1lf\n", sum, gpa + 1e-9);
	}
}
