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
//BOJ #1713
typedef long long ll;
typedef unsigned long long ull;

int good[101];
int isinphoto[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	int num;
	int size = 0;
	for (int i = 1; i <= s; i++) {
		cin >> num;
		good[num]++;
		if (!isinphoto[num]) {
			if (size == n) {
				pair<int, int> m = { 987654321,-1 };
				for (int i = 1; i <= 100; i++) {
					if (!isinphoto[i]) {
						continue;
					}
					if (m.first > good[i]) {
						m.first = good[i];
						m.second = i;
					} else if (m.first == good[i]) {
						if (isinphoto[m.second] > isinphoto[i]) {
							m.second = i;
						}
					}
				}
				isinphoto[m.second] = 0;
				good[m.second] = 0;
				size--;
			}
			isinphoto[num] = i;
			size++;
		}
	}
	for (int i = 1; i <= 100; i++) {
		if (isinphoto[i]) {
			cout << i << ' ';
		}
	}
}
