#include <iostream>
#include <string>
using namespace std;
//BOJ #15104
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	if (s.size() % 2 == 1) {
		cout << "Odd.";
	} else {
		cout << "Or not.";
	}
	return 0;
}