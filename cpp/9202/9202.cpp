#include <iostream>
#include <string>
using namespace std;

struct Node {
  Node* ptr[26];
  int eow;
} pool[1200001];
int pidx = 0;
Node root;

Node* getPool() {
  return &pool[pidx++];
}

void add(string& s) {
  int size = s.size();
  Node* here = &root;
  for (int i = 0; i < size; i++) {
    if (here->ptr[s[i] - 'A'] == nullptr) {
      here->ptr[s[i] - 'A'] = getPool();
    }
    here = here->ptr[s[i] - 'A'];
  }
  here->eow = 1;
}

bool find(string& s, int c) {
  int size = s.size();
  Node* here = &root;
  for (int i = 0; i < size; i++) {
    if (here->ptr[s[i] - 'A'] == nullptr) {
      return false;
    }
    here = here->ptr[s[i] - 'A'];
  }
  if (here->eow && here->eow != c) {
    here->eow = c;
    return true;
  }
  return false;
}

string word;
string maxword;
int score;
int cnt;
char map[4][4];
int visited[4][4];
int pos[8][2] = { {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };

void findword(int y, int x, int tc, int w) {
  if (word.size() > 8) {
    return;
  }
  if (find(word, w)) {
    cnt++;
    if (word.size() == maxword.size() && maxword > word) {
      maxword = word;
    }
    if (word.size() > maxword.size()) {
      maxword = word;
    }
    switch (word.size()) {
    case 3:
    case 4:
      score += 1;
      break;
    case 5:
      score += 2;
      break;
    case 6:
      score += 3;
      break;
    case 7:
      score += 5;
      break;
    case 8:
      score += 11;
      break;
    }
  }
  for (int i = 0; i < 8; i++) {
    int nx = x + pos[i][0];
    int ny = y + pos[i][1];
    if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
    if (visited[ny][nx] == tc) continue;
    word.push_back(map[ny][nx]);
    visited[ny][nx] = tc;
    findword(ny, nx, tc, w);
    visited[ny][nx] = 0;
    word.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int w;
  cin >> w;
  string s;
  for (int i = 0; i < w; i++) {
    cin >> s;
    add(s);
  }
  int B;
  cin >> B;
  for (int b = 1; b <= B; b++) {
    word.clear();
    maxword.clear();
    cnt = 0;
    score = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> map[i][j];
      }
    }
    int tc = 1;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        word.push_back(map[i][j]);
        visited[i][j] = tc;
        findword(i, j, tc++, b + 1);
        word.pop_back();
      }
    }
    cout << score << ' ' << maxword << ' ' << cnt << '\n';
  }
}