#include <iostream>
using namespace std;
//BOJ #10886

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> ans;
		ans ? cnt++ : cnt--;
	}
	if (cnt <= 0) {
		cout << "Junhee is not cute!";
	} else {
		cout << "Junhee is cute!";
	}
	return 0;
}