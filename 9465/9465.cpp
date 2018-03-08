#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #9465
typedef long long ll;
ll map[2][100001];
ll memo[3][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int n;
	while(t--) {
		cin>>n;
		for(int i = 0; i<2; i++) {
			for(int j = 1; j<=n; j++) {
				cin>>map[i][j];
			}
		}
		for(int i = 1; i<=n; i++) {
			memo[0][i] = max(memo[2][i-1], memo[1][i-1])+map[0][i];
			memo[1][i] = max(memo[2][i-1], memo[0][i-1])+map[1][i];
			memo[2][i] = max({memo[0][i-1],memo[1][i-1],memo[2][i-1]});
		}
		cout<<max({memo[0][n],memo[1][n],memo[2][n]})<<'\n';
	}
	/*
	3���� ���̽�
	memo[n][i] -> n��ġ�� ��ƼĿ�� ������ �ִ밪 (2�� �Ȱ���)
	���� ��ƼĿ�� �������,�ؿ� ��ƼĿ�� �������, �Ȱ������
	�� : ���ʿ� �ִ� �� ������ ���ʾƷ��� �Ȱ���+�ڽ�
	�Ʒ� : ������,�Ȱ���+�ڽ�
	�� : ������,�Ʒ�,�Ȱ��� �߿� �ִ밪
	*/
	return 0;
}