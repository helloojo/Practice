#include <iostream>
#include <string>
using namespace std;
pair<bool, bool> cmp[26];		//first isexist, second first referenced
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	string a, b;
	while (t--) {
		cin >> a >> b;
		for (int i = 0; i < 26; i++) {
			cmp[i].first = false;
			cmp[i].second = false;
		}
		int as = a.size();
		int acnt = 0;
		int bs = b.size();
		int bcnt = 0;
		for (int i = 0; i < as; i++) {
			if (!cmp[a[i] - 'A'].first) {
				acnt++;
				cmp[a[i] - 'A'].first = true;
			}
		}
		for (int i = 0; i < bs; i++) {
			if (cmp[b[i] - 'A'].first && !cmp[b[i] - 'A'].second) {
				bcnt++;
				cmp[b[i] - 'A'].second = true;
			} else if (!cmp[b[i] - 'A'].first) {
				bcnt = -1;
				break;
			}
		}
		if (acnt == bcnt) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}