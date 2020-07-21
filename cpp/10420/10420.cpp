#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #10420
typedef long long ll;
typedef unsigned long long ull;

struct date {
	int year;
	int month;
	int day;
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	date() {
		year = 2014;
		month = 4;
		day = 2;
	}
	void add() {
		day++;
		if(day > mon[month]) {
			month++;
			day = 1;
		}
		if(month > 12) {
			year++;
			month = 1;
			if(year % 400==0) {
				mon[2] = 29;
			} else if(year % 100 != 0 && year % 4 == 0) {
				mon[2] = 29;
			} else {
				mon[2] = 28;
			}
		}
	}
	void print() {
		printf("%04d-%02d-%02d", year, month, day);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	date d;
	for(int i = 1; i < n; i++) {
		d.add();
	}
	d.print();
	
}
