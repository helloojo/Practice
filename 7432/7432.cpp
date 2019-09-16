#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;

struct Node {
  map<string, Node> ptr;
};

Node root;


void add(vector<string>& v) {
  Node* here = &root;
  for (int i = 0; i < v.size(); i++) {
    if (here->ptr.find(v[i])==here->ptr.end()) {
      here->ptr[v[i]] = Node();
    }
    here = &here->ptr[v[i]];
  }
}

void print(Node* here = &root, int depth = 0) {
  if (here->ptr.empty()) {
    return;
  }
  for (auto& s : here->ptr) {
    for (int i = 0; i < depth; i++) {
      cout << ' ';
    }
    cout << s.first << '\n';
    print(&s.second, depth + 1);
  }
}

char str[81];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<string> v;
  char* r;
  for (int i = 0; i < n; i++) {
    v.clear();
    cin >> str;
    r = strtok(str, "\\");
    v.push_back(r);
    while (r != NULL) {
      r = strtok(NULL, "\\");
      if (r != NULL) {
        v.push_back(r);
      }
    }
    add(v);
  }
  print();
}