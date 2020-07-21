#include <iostream>
#include <list>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;


int n, m, k;
int pos[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1} };
int potion[11][11];
int nutrient[11][11];
queue<pair<int, pair<int, int>>> deads;
queue<pair<int, int>> growth;
deque<int> trees[11][11];

/*
����� ��� ĭ�� 5��ŭ ��� ����
M���� ������ ������ ���� ���� ��ĭ�� �������� �԰���
�� -> ������ ���̸�ŭ ��и԰� ���� 1 ����
   -> ���̰� � �������� ����� ����
   -> ���̸�ŭ ����� ���� �� ���� ������ ����
����  -> ���� ���� ������ ���̸� 2�� ���� ���� ������� ����
����  -> ���̰� 5�� ����� ���� ���� ������ 8�� ĭ�� ���� 1�� ���� ����
�ܿ�  -> A[r][c] ��ŭ ���� ���� ����
K�� �� ���� ���� ���ϱ�
*/

void spring() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (trees[i][j].size()) {
        for (auto it = trees[i][j].begin(); it != trees[i][j].end(); ++it) {
          auto& p = *it;
          if (p > nutrient[i][j]) {
            deads.push({ p,{i,j} });
            it = trees[i][j].erase(it);
            it--;
            continue;
          }
          nutrient[i][j] -= p;
          ++p;
          if (p % 5 == 0) {
            growth.push({ i,j });
          }
        }
      }
    }
  }
}

void summer() {
  while (!deads.empty()) {
    auto age = deads.front().first;
    auto p = deads.front().second;
    deads.pop();
    nutrient[p.first][p.second] += age / 2;
  }
}

void fall() {
  while (!growth.empty()) {
    auto p = growth.front();
    growth.pop();
    for (int i = 0; i < 8; i++) {
      int nx = p.second + pos[i][0];
      int ny = p.first + pos[i][1];
      if (nx<1 || ny<1 || nx>n || ny>n) {
        continue;
      }
      trees[ny][nx].push_front(1);
    }
  }
}

void winter() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      nutrient[i][j] += potion[i][j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> potion[i][j];
      nutrient[i][j] = 5;
    }
  }
  int x, y, z;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    trees[x][y].push_back(z);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (trees[i][j].size()) {
        sort(trees[i][j].begin(), trees[i][j].end());
      }
    }
  }

  for (int i = 0; i < k; i++) {
    spring();
    summer();
    fall();
    winter();
  }

  int ret = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ret += trees[i][j].size();
    }
  }
  cout << ret;

  return 0;
}