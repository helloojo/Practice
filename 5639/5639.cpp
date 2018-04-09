#include <iostream>
using namespace std;
//BOJ #5639

struct Node {
	int value;
	Node* left;
	Node* right;
};
Node* addtree(Node* here, int num) {
	if (here == nullptr) {
		here = new Node;
		here->left = nullptr;
		here->right = nullptr;
		here->value = num;
		return here;
	}
	if (here->value < num) {
		here->right=addtree(here->right, num);
	} else {
		here->left=addtree(here->left, num);
	}
	return here;
}

void postorder(Node* here) {
	if (here == nullptr) {
		return;
	}
	postorder(here->left);
	postorder(here->right);
	cout << here->value << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num = 0;
	Node* root = nullptr;
	while (cin >> num) {
		root=addtree(root, num);
	}
	postorder(root);
	return 0;
}