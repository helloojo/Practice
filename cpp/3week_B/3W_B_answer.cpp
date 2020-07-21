#include <iostream>
#include <cstring>
using namespace std;

int n, k, a, b, r, c,maxc=1;
pair<int, int> num[100001];
int depth[100001];
bool use[101];

inline void setdepth(int a, int b) {
	if (depth[a] < depth[num[a].first]) {
		depth[a] = depth[num[a].first] + 1;
	}
	if (depth[b] < depth[num[b].first]) {
		depth[b] = depth[num[b].first] + 1;
	}
}

int finds(int a, int b) {
	if (a == b) return 0;
	setdepth(a, b);
	if (depth[a] > depth[b]) {
		use[num[a].second] = true;
		return finds(num[a].first, b);
	} else if (depth[a] == depth[b])  {
		use[num[a].second] = true;
		use[num[b].second] = true;
		return finds(num[a].first, num[b].first);
	} else {
		use[num[b].second] = true;
		return finds(a, num[b].first);
	}
}

inline int kinds(int a, int b) {
	finds(a, b);
	int cnt = 0;
	for (int i = 1; i <= maxc; i++) {
		if (use[i]) {
			cnt++;
		}
	}
	return cnt;
}

inline void under(int a, int b) {
	num[a].first = b;
	depth[a] = depth[b] +1;
}

int document(int a, int b, int c) {
	if (a == b) return 0;	
	setdepth(a, b);
	if (depth[a] > depth[b]) {
		num[a].second = c;
		return document(num[a].first, b, c);
	} else if (depth[a] == depth[b]) {
		num[a].second = c;
		num[b].second = c;
		return document(num[a].first, num[b].first, c);
	} else {
		num[b].second = c;
		return document(a, num[b].first, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	num[1] = make_pair(1, 1);;
	depth[1] = 0;
	for (int i = 2; i <= n; i++) {
		num[i] = make_pair(1, 1);
		depth[i] = 1;
	}
	while (k--) {
		cin >> r >> a >> b;
		switch (r)
		{
		case 1:
			cin >> c;
			document(a, b, c);
			maxc = maxc < c ? c : maxc;
			break;
		case 2:
			under(a, b);
			break;
		case 3:
			memset(use, 0, sizeof(use));
			cout << kinds(a, b) << '\n';
			break;
		}
	}
	return 0;
}