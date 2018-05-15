#include <iostream>
using namespace std;
//BOJ #4256

int preorder[1001];
int inorder[1001];

void postorder(int s1, int e1,int s2,int e2) {
	if (e1 == s1) {
		return;
	}
	int root = preorder[s1];
	int i;
	for (i = s2; i < e2; i++) {
		if (root == inorder[i]) {
			break;
		}
	}
	postorder(s1 + 1, i + 1, s2, i);
	postorder(i + 1, e1, i + 1, e2);
	cout << root << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> preorder[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> inorder[i];
		}
		postorder(0, n, 0, n);
		cout << '\n';
	}
}