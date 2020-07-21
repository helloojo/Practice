#include <iostream>
#include <string>
using namespace std;
//BOJ #6581

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string buf = "";
	string hr = "--------------------------------------------------------------------------------\n";
	string br = "\n";
	string cur;
	while (cin >> cur) {
		if (cur == "<br>") {
			if (buf.empty()) {
				cout << br;
			} else {
				cout << buf << br;
				buf = "";
			}
		} else if (cur == "<hr>") {
			if (buf.empty()) {
				cout << hr;
			} else {
				cout << buf << '\n' << hr;
				buf = "";
			}
		} else {
			if (buf.size() + cur.size()> 80) {
				cout << buf << '\n';
				buf = "";
			}
			buf += (cur + " ");
		}
	}
	cout << buf << br;
}