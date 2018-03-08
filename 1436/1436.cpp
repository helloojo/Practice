#include <iostream>
using namespace std;
//BOJ #1436
int order[] = {0,1,2,3,4,5,0,1,2,3,4,5,6,7,8,9,7,8,9};
int main() {
	int n;
	cin>>n;
	int first = n/19;
	int second = n%19;
	if(!second) {
		first--;
		second = 19;
	}
	if(first) {
		printf("%d", first);
	}
	if((second>=0&&second<=6)||(second>=17&&second<=18)) {
		if(second) {
			printf("%d666", order[second-1]);
		} else {
			printf("666");
		}
	} else {
		printf("666%d", order[second-1]);
	}

	return 0;
}