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
//BOJ #2456
typedef long long ll;
typedef unsigned long long ull;

struct cand {
	int three;
	int two;
	int one;
	int sum;
	int idx;
};

cand arr[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		for (int j = 0; j < 3; j++) {
			arr[j].idx = j + 1;
			cin >> num;
			arr[j].sum += num;
			switch (num) {
			case 1:
				arr[j].one++;
				break;
			case 2:
				arr[j].two++;
				break;
			case 3:
				arr[j].three++;
				break;
			}
		}
	}
	sort(arr, arr + 3, [](cand a, cand b) {
		if (a.sum == b.sum) {
			if (a.three == b.three) {
				if (a.two == b.two) {
					return true;
				}
				return a.two > b.two;
			}
			return a.three > b.three;
		}
		return a.sum > b.sum;
	});
	if (arr[0].sum == arr[1].sum && arr[0].three==arr[1].three && arr[0].two==arr[1].two) {
		cout << "0 " << arr[0].sum;
	} else {
		cout << arr[0].idx << ' ' << arr[0].sum;
	}
}
