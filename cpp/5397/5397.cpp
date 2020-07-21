#include <iostream>
#include <string>
#include <list>
#include <stack>
using namespace std;
//BOJ #5397

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	string s;
	list<char> back;
	list<char> front;
	while (t--) {
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
			case '<':
				if (!front.empty()) {
					back.push_front(front.back());
					front.pop_back();
				}
				break;
			case '>':
				if (!back.empty()) {
					front.push_back(back.front());
					back.pop_front();
				}
				break;
			case '-':
				if (!front.empty()) {
					front.pop_back();
				}
				break;
			default:
				front.push_back(s[i]);
				break;
			}
		}
		while (!front.empty()) {
			cout << front.front();
			front.pop_front();
		}
		while (!back.empty()) {
			cout << back.front();
			back.pop_front();
		}
		cout << '\n';
	}
}