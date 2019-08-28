#include <iostream>
#include <algorithm>
using namespace std;

char word[15];
char arr[15];
void print(int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }
  cout << '\n';
}
void find(int here,int c,int l,int j,int m, int idx = 1) {
  if (idx == l) {
    if (j >= 2 && m >= 1) {
      print(l);
    }
    return;
  }
  for (int i = here + 1; i < c; i++) {
    arr[idx] = word[i];
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'o' || word[i] == 'u' || word[i] == 'i') {
      find(i, c, l,j,m+1, idx + 1);
    } else {
      find(i, c, l,j+1,m, idx + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int l, c;
  cin >> l >> c;
  for (int i = 0; i < c; i++) {
    cin >> word[i];
  }
  sort(word, word + c);
  for (int i = 0; i < c; i++) {
    arr[0] = word[i];
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'o' || word[i] == 'u' || word[i] == 'i') {
      find(i, c, l, 0, 1);
    } else {
      find(i, c, l, 1, 0);
    }
  }
}