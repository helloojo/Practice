#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #1722
typedef unsigned long long ll;
int num[20];
int refer[20];
bool use[21];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	ll k;
	cin >> n;
	cin >> m;
	int cur = n;
	int number = 1;
	int cnt = 1;
	ll fact = 1;
	ll order = 1;
	int index = 0;
	for (int i = 1; i <= n; i++) {
		fact *= i;
	}
	switch (m)
	{
	case 1:
		cin >> k;
		while (fact != 1) {
			fact /= cur;
			number = 1;
			cnt = 1;
			while (true) {
				if (!use[number]) {
					if (order + fact * cnt > k) {
						cout << number << ' ';
						use[number] = true;
						order += fact * (cnt - 1);
						break;
					} else {
						number++;
						cnt++;
					}
				} else {
					number++;
				}
			}
			cur--;
		}
		for (int i = 1; i<=n; i++) {
			if (!use[i]) {
				cout << i;
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		order = 1;
		while (fact != 1) {
			fact /= cur;
			cnt = 1;
			number = 1;
			for (int i = 1; i <= n; i++) {
				if (number == num[index] && !use[number]) {
					break;
				} else if (!use[number]) {
					cnt++;
					number++;
				} else {
					number++;
				}
			}
			use[number] = true;
			order += fact * (cnt - 1);
			cur--;
			index++;
		}
		cout << order;
		break;
	}
	return 0;
}