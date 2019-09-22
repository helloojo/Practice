#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

char t[1000010];
char p[1000010];
int fail[1000010];

void failure(const char* pattern, int pattern_size) {
  fail[0] = 0;
  int j = 0;
  for (int i = 1; i < pattern_size; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = fail[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      fail[i] = ++j;
    }
  }
}

int answer[1000010];
int aidx = 0;

void KMP(const char* text, const char* pattern, int text_size, int pattern_size) {
  int j = 0;
  for (int i = 0; i < text_size; i++) {
    while (j > 0 && text[i] != pattern[j]) {
      j = fail[j - 1];
    }
    if (text[i] == pattern[j]) {
      if (j == pattern_size - 1) {
        answer[aidx++] = (i - j + 1);
        j = fail[j];
      } else {
        j++;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.getline(t, 1000001);
  cin.getline(p, 1000001);
  int t_size = strlen(t);
  int p_size = strlen(p);

  failure(p, p_size);
  KMP(t, p, t_size, p_size);
  cout << aidx << '\n';
  for (int i = 0; i < aidx; i++) {
    cout << answer[i] << ' ';
  }
}