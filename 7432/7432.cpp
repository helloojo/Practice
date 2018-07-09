#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
//BOJ #7432
map<string, set<string>> tree;
void print(string key, int depth) {
	if (tree[key].empty()) {
		return;
	}
	set<string> &here = tree[key];
	for (auto i= here.begin(); i != here.end(); i++) {
		for (int j = 0; j < depth; j++) {
			cout << ' ';
		}
		cout << *i << '\n';
		print(*i, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	char s[100] = "";
	set<string> root;
	char* r;
	for (int i = 0; i < n; i++) {
		cin >> s;
		r = strtok(s, "\\");
		string ro = r;
		root.insert(ro);
		while (r != NULL) {
			r = strtok(NULL, "\\");
			if (r != NULL) {
				tree[ro].insert(r);
				ro = r;
			}
		}
	}
	for (auto i = root.begin(); i != root.end(); i++) {
		string key = *i;
		cout << key << '\n';
		print(key, 1);
	}
}
