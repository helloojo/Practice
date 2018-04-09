#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
//BOJ #12789
int arr[1001];
stack<int> st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int order = 1;
	int in = 0;
	for (int i = 0; i < n; i++, in++) {
		cin >> arr[in];
		if (arr[in] != order) {
			st.push(arr[in]);
			in--;
		} else if (st.top() == order) {
			st.pop();
			order++;
		} else {
			order++;
		}
	}
	bool can = true;
	if (st.empty() && order != n) {
		can = false;
	}
	while (!st.empty()) {
		if (st.top() == order) {
			st.pop();
			order++;
		} else {
			can = false;
			break;
		}
	}
	cout << (can ? "Nice" : "Sad");

	return 0;
}