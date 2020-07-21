#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
//BOJ #9019
queue<pair<int, string>> q;
bool visited[10001];

int D(int n) {
	return (2 * n) % 10000;
}
int S(int n) {
	if (n) {
		n--;
	} else {
		n = 9999;
	}
	return n;
}
int L(int n) {
	int d[4];
	d[0] = n / 1000;
	d[1] = (n % 1000) / 100;
	d[2] = (n % 100) / 10;
	d[3] = n % 10;
	n = d[1] * 1000 + d[2] * 100 + d[3] * 10 + d[0];
	return n;
}
int R(int n) {
	int d[4];
	d[0] = n / 1000;
	d[1] = (n % 1000) / 100;
	d[2] = (n % 100) / 10;
	d[3] = n % 10;
	n = d[3] * 1000 + d[0] * 100 + d[1] * 10 + d[2];
	return n;
}

string bfs(int src, int dest) {
	visited[src] = true;
	q.push({ src,"" });
	string ret = "qwertyuiopasdfghjklzxcvbnmqwertyuiopasfwefsefesfsdfkjasehfiewhfiwofihawehfiowehifohweofhiodfghjklzxcvbnm";
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.first == dest) {
			if (ret.size() > p.second.size()) {
				ret = p.second;
			}
		}
		for (int i = 0; i < 4; i++) {
			int temp = 0;
			string temps = p.second;
			if (ret.size() < p.second.size() + 1) continue;
			switch (i)
			{
			case 0:
				temp = D(p.first);
				temps += "D";
				break;
			case 1:
				temp = S(p.first);
				temps += "S";
				break;
			case 2:
				temp = L(p.first);
				temps += "L";
				break;
			case 3:
				temp = R(p.first);
				temps += "R";
				break;
			}
			if (visited[temp]) continue;
			visited[temp] = true;
			q.push({ temp,temps });
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		memset(visited, 0, sizeof(visited));
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
}