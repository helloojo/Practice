#include <iostream>
#include <queue>
#include <functional>
#include <fstream>
using namespace std;

struct Process {
	int priority;
	int process_number;
	int time;
	bool operator>(const Process& p) {
		return priority > p.priority;
	}
};

class RR {
private:
	priority_queue<Process, vector<Process>, greater<Process>> pq;
	int timeq;
public:
	RR(int t) {
		timeq = t;
	}
	void push(Process p) {
		pq.push(p);
	}
	Process pop() {
		Process p = pq.top();
		pq.pop();
		return p;
	}
};

class CFS {
private:
	priority_queue<Process, vector<Process>, greater<Process>> pq;
public:
	void push(Process p) {
		pq.push(p);
	}
	Process pop() {

	}
	int getWeight(const Process& p) {
		int pri = p.priority;
		if (pri <= 109) {
			return 10;
		} else if (pri <= 119) {
			return 8;
		} else if (pri <= 129) {
			return 6;
		} else {
			return 4;
		}
	}
};

int main() {
	ifstream in("input.txt");
	Process temp;
	RR r(2);
	CFS c;
	int pr, pn, ti;
	while (in >> pr >> pn >> ti) {
		temp.priority = pr;
		temp.process_number= pn;
		temp.time = ti;
		if (temp.priority < 100) {
			r.push(temp);
		} else {
			c.push(temp);
		}
	}
	return 0;
}