#include <iostream>
#include <queue>
using namespace std;
queue<int> q[256];
int fruit[8];
int exist = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	char d;
	int f;
	int minidx = 0;
	int minorder = -1;
	int order = 0;
	cin >> n;
	while (n--) {
		cin >> d;
		switch (d) {
		case 'D':
			cin >> f;
			fruit[f]++;
			exist |= (1 << f);
			minorder = 987654321;
			minidx = 987654321;
			for (int i = 1; i < 256; i++) {
				if ((exist == (exist | i)) && !q[i].empty()) {
					if (q[i].front() < minorder) {
						minorder = q[i].front();
						minidx = i;
					}
				}
			}
			if (minorder != 987654321) {
				cout << minorder << '\n';
				q[minidx].pop();
				for (int i = 0; i < 8; i++) {
					if (minidx & (1 << i)) {
						if (fruit[i] - 1 == 0) {
							exist ^= (1 << i);
						}
						fruit[i]--;
					}
				}
			}			
			break;
		case 'O':
			cin >> m;
			int cur = 0;
			for (int i = 0; i < m; i++) {
				cin >> f;
				cur |= (1 << f);
			}
			q[cur].push(order++);
			if (exist == (exist | cur)) {
				cout << q[cur].front() << '\n';
				q[cur].pop();
				for (int i = 0; i < 8; i++) {
					if (cur & (1 << i)) {
						if (fruit[i] - 1 == 0) {
							exist ^= (1 << i);
						}
						fruit[i]--;
					}
				}
			}
			break;
		}
	}
}