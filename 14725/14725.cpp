#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Node {
  map<string, Node> m;
};

Node root;

void print(Node* here, int depth = 0) {
  if (here->m.empty()) {
    return;
  }

  for (auto& it : here->m) {
    for (int i = 0; i < depth; i++) {
      cout << "--";
    }
    cout << it.first << '\n';
    print(&it.second, depth + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    string s;
    Node* temp = &root;
    for (int j = 0; j < k; j++) {
      cin >> s;
      if (temp->m.find(s) == temp->m.end()) {
        temp->m[s] = { map<string,Node>() };
      }
      temp = &temp->m[s];
    }
  }
  print(&root);
}
