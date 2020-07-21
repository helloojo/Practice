#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//BOJ #11723

bool arr[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> m;
	string q;
	int num;
	while (m--) {
		cin >> q;
		if (q == "add") {
			cin >> num;
			arr[num] = true;
		} else if (q == "remove") {
			cin >> num;
			arr[num] = false;
		} else if (q == "check") {
			cin >> num;
			cout << arr[num] << '\n';
		} else if (q == "all") {
			for (int i = 1; i <= 20; i++) {
				arr[i] = true;
			}
		} else if (q == "empty") {
			memset(arr, 0, sizeof(0));
		} else if (q == "toggle") {
			cin >> num;
			arr[num] = !arr[num];
		}
	}
	return 0;
}