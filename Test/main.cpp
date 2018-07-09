#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> tree[27];

void pre(int t) {
	if (t == 0) return;
	cout << (char)(t + 'A'-1);
	pre(tree[t].first);
	pre(tree[t].second);
}
void post(int t) {
	if (t == 0) return;
	post(tree[t].first);
	post(tree[t].second);
	cout << (char)(t + 'A'-1);
}
void in(int t) {
	if (t == 0) return;
	in(tree[t].first);
	cout << (char)(t + 'A'-1);
	in(tree[t].second);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	char a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (b != '.') {
			tree[a - 'A' + 1].first = b - 'A' + 1;
		}
		if (c != '.') {
			tree[a - 'A' + 1].second = c - 'A' + 1;
		}
	}
	pre(1);
	cout << '\n';
	in(1);
	cout << '\n';
	post(1);
	return 0;
}