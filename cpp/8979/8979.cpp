#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #8979

struct nation
{
	int num;
	int gold;
	int sil;
	int bron;
	int rank;
};

nation num[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	nation* ref;
	for (int i = 0; i < n; i++) {
		cin >> num[i].num >> num[i].gold >> num[i].sil >> num[i].bron;
		if (num[i].num == k) {
			ref = &num[i];
		}
	}
	int rank = 1;
	for (int i = 0; i < n; i++) {
		if (num[i].num == k) {
			continue;
		} else {
			if (num[i].gold > ref->gold) {
				rank++;
			} else if (num[i].gold == ref->gold) {
				if (num[i].sil > ref->sil) {
					rank++;
				} else if (num[i].sil == ref->sil) {
					if (num[i].bron > ref->bron) {
						rank++;
					}
				}
			}
		}
	}
	cout << rank;

	return 0;
}