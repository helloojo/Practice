#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//BOJ #1252

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	string ret = "";
	int up = 0;
	for (int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0;) {
		int temp;
		if (i == -1) {
			temp = b[j] - '0' + up;
			j--;
		} else if (j == -1) {
			temp = a[i] - '0' + up;
			i--;
		} else {
			temp = (a[i] - '0') + (b[j] - '0') + up;
			i--;
			j--;
		}
		up = 0;
		switch (temp)
		{
		case 0:
		case 1:
			ret += (temp + '0');
			break;
		case 2:
		case 3:
			up = 1;
			temp -= 2;
			ret += (temp + '0');
			break;
		}
	}
	if (up) {
		ret += "1";
	}
	while (ret.back() != '1') {
		ret.pop_back();
	}
	reverse(ret.begin(), ret.end());
	cout << ret;
}