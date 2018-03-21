#include <iostream>
#include <cstring>
using namespace std;
int abit;
int bbit;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int as, bs;
	char a[81], b[81];
	while (t--) {
		abit = 0;
		bbit = 0;
		cin >> a >> b;
		as = strlen(a);
		bs = strlen(b);
		for (int i = 0; i < as; i++) {
			abit |= (1 << (a[i] - 'A'));
		}
		for (int i = 0; i < bs; i++) {
			bbit |= (1 << (b[i] - 'A'));
		}
		cout<<((abit == bbit) ? "YES\n" : "NO\n");
	}
	return 0;
}