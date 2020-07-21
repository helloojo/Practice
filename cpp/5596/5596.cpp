#include <iostream>
using namespace std;
//BOJ #5596
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int suma = 0;
	int sumb = 0;
	int a;
	for (int i = 0; i < 4; i++) {
		cin >> a;
		suma += a;
	}
	for (int i = 0; i < 4; i++) {
		cin >> a;
		sumb += a;
	}
	if (suma >= sumb) {
		cout << suma;
	} else {
		cout << sumb;
	}
	return 0;
}