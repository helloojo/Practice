#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int memo[1005][1005];	//memo[i][j] -> pos[i]��ġ�� ���� pos[j]��ġ�� ��� �ִܰŸ�
int pos[1005];
int n, m;

/*
�켱 ���̳��� �迭�� ���Ǹ� memo[i, j] = i��°�� ���ϰ�, j��°�� ����� ���� �� �ִܰŸ�.��� ����.
�̶� i - 1��° ����� ������ �ڱ� ���� ���ľ������� �츮�� ������ ����
memo[i - 1][j]
memo[j][i - 1] �̴�.

memo[i - 1][j]
memo[i][j] = memo[i - 1][j] + i - 1��° ��ġ���� i��° ��ġ���� �Ÿ�. //���� �̵������� ��
memo[i - 1][i] = memo[i - 1][j] + j���� ��ġ���� i��° ��ġ������ �Ÿ�. //��� �̵������� ��

memo[j][i - 1]
memo[i][i - 1] = memo[j][i - 1] + j��° ��ġ���� i���� ��ġ���� �Ÿ�.   //���� �̵����� ��
memo[j][i] = memo[j][i - 1] + i - 1��° ��ġ���� i��° ��ġ������ �Ÿ�. //��� �̵����� ��
������ �ʱ���ġ 0�� ��ġ0, ����� �ʱ���ġ n�� ��ġ1, �׵ڷ� ������1�� ��ġ2 ������2�� ��ġ3
�׸��� �迭�� ��� �������� �ʱ�ȭ �صθ�, memo[0][1], �� �ʱ���´� 0���� �ʱ�ȭ �Ѵ�.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	int ret = 0;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		
		for (int i = 2; i < m + 2; i++) {
			cin >> pos[i];
		}
		for (int i = 0; i < m + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				memo[i][j] = 987654321;
			}
		}
		pos[0] = 0;
		pos[1] = n;

		memo[0][1] = 0;
		ret = 987654321;
		for (int i = 2; i < m + 2; i++) {
			for (int j = 0; j < i; j++) {
				memo[i][i - 1] = min(memo[i][i - 1], memo[j][i - 1] + abs(pos[j] - pos[i]));
				memo[j][i] = min(memo[j][i], memo[j][i - 1] + abs(pos[i - 1] - pos[i]));
				if (i == m + 1) {
					ret = min({ ret, memo[j][i],memo[i][i - 1] });
				}
			}
			for (int j = 0; j < i; j++) {
				memo[i][j] = min(memo[i][j], memo[i - 1][j] + abs(pos[i - 1] - pos[i]));
				memo[i - 1][i] = min(memo[i - 1][i], memo[i - 1][j] + abs(pos[j] - pos[i]));
				if (i == m + 1) {
					ret = min({ ret,memo[i][j],memo[i - 1][i] });
				}
			}
		}
		cout << ret << '\n';
	}
	return 0;
}