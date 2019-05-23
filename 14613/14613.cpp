#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
//BOJ #14613
typedef long long ll;
typedef unsigned long long ull;

double memo[21][4000];	//mmr[i][k] -> i게임 시 k일 확률

double w, l, d;
int main() {
	scanf("%lf %lf %lf", &w, &l, &d);
	memo[0][2000] = 1;
	for (int i = 1; i <= 20; i++) {
		for (int j = 1000; j < 3500; j++) {
			memo[i][j] = (memo[i - 1][j - 50] * w + memo[i - 1][j] * d + memo[i - 1][j + 50] * l);
		}
	}
	double possible[5];
	for (int j = 1000; j < 3500; j++) {
		if (j < 1500) {
			possible[0] += memo[20][j];
		} else if (j < 2000) {
			possible[1] += memo[20][j];
		} else if (j < 2500) {
			possible[2] += memo[20][j];
		} else if (j < 3000) {
			possible[3] += memo[20][j];
		} else {
			possible[4] += memo[20][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%.08lf\n", possible[i]);
	}
}
