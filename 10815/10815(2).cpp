#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #10815
int arr[500001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int m;
	cin >> m;
	int num;
	while (m--) {
		cin >> num;
		if (binary_search(arr,arr+n,num)) {
			cout << "1 ";
		} else {
			cout << "0 ";
		}
	}
}