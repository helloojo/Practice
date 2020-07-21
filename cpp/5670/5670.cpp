#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;

struct Node {
  Node* child;
  Node* sibling;
  char ch;
  bool eow;
} pool[1000010];
Node root[26];
int pidx = 0;

Node* getPool() {
  return &pool[pidx++];
}

void init() {
  memset(root, 0, sizeof(root));
  memset(pool, 0, sizeof(Node) * pidx);
  pidx = 0;
}

void add(string& s) {
  int size = s.size();
  Node* here = &root[s[0] - 'a'];
  for (int i = 1; i < size; i++) {
    if (here->child == nullptr) {
      here->child = getPool();
      here->child->ch = s[i];
      here = here->child;
    } else if (here->child->ch == s[i]) {
      here = here->child;
    } else {
      Node* temp = here->child;
      while (temp->sibling != nullptr && temp->sibling->ch != s[i]) {
        temp = temp->sibling;
      }
      if (temp->sibling == nullptr) {
        temp->sibling = getPool();
        temp->sibling->ch = s[i];
      }
      here = temp->sibling;
    }
  }
  here->eow = true;
}

int find(string& s) {
  int size = s.size();
  int cnt = 1;
  Node* here = &root[s[0] - 'a'];
  for (int i = 1; i < size; i++) {
    if (here->child->sibling != nullptr) {
      cnt++;
    } else if (here->eow && here->child != nullptr) {
      cnt++;
    }
    if (here->child->ch == s[i]) {
      here = here->child;
    } else {
      Node* temp = here->child;
      while (temp->sibling->ch != s[i]) {
        temp = temp->sibling;
      }
      here = temp->sibling;
    }
  }
  return cnt;
}

string dic[100001];

int main() {
  int n;
  cout << fixed << setprecision(2);
  while (cin >> n) {
    init();
    for (int i = 0; i < n; i++) {
      cin >> dic[i];
      add(dic[i]);
    }
    double avg = 0;
    for (int i = 0; i < n; i++) {
      avg += find(dic[i]);
    }
    cout << avg / n << '\n';
  }
}