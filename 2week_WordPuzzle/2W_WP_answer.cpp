#include <iostream>
#include <string>
#include <cstring>
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
		memset(cmp, 0, sizeof(cmp));
		int as = a.size();
		int bs = b.size();
		int bcnt = 0;
for (int i = 0; i < as; i++) {
if (!cmp[a[i] - 'A'].first) {
cmp[a[i] - 'A'].first = true;
}
}
for (int i = 0; i < bs; i++) {
if (cmp[b[i] - 'A'].first && !cmp[b[i] - 'A'].second) {
bcnt++;
cmp[b[i] - 'A'].second = true;
} else if (!cmp[b[i] - 'A'].first) {		//not exist
bcnt = -1;
break;
}
}
		if (as == bcnt) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}