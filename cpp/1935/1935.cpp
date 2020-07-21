#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #1918
typedef long long ll;
typedef unsigned long long ull;
stack<double> post;
string postfix;
double cnt[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cin >> postfix;
	for (int i = 0; i < n; i++) {
		cin >> cnt[i];
	}
	for (int i = 0; i < postfix.size(); i++) {
		double first = 0;
		double second = 0;
		double ret=0;
		if (postfix[i] >= 'A' && postfix[i] <= 'Z') {
			post.push(cnt[postfix[i] - 'A']);
		} else {
			switch (postfix[i]) {
			case '*':
				second= post.top();
				post.pop();
				first= post.top();
				post.pop();
				ret = first * second;
				break;
			case '/':
				second = post.top();
				post.pop();
				first = post.top();
				post.pop();
				ret = first / second;
				break;
			case '+':
				second = post.top();
				post.pop();
				first = post.top();
				post.pop();
				ret = first + second;
				break;
			case '-':
				second = post.top();
				post.pop();
				first = post.top();
				post.pop();
				ret = first - second;
				break;
			}
			post.push(ret);
		}
	}
	printf("%.2lf", post.top());
}
