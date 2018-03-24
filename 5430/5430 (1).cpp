#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//BOJ #5430
string num[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	string p;
	int n;
	string input;
	while(t--) {
		cin>>p;
		cin>>n;
		cin>>input;
		int start = 0;
		int end = n;
		for(int i = 0; i<n; i++) {
			num[i] = "";
		}
		int j = 0;
		for(int i = 0; i<input.size(); i++) {
			if(input[i]>='0' && input[i]<='9') {
				num[j] += input[i];
			} else if(input[i]==',') {
				j++;
			}
		}
		bool can = true;
		for(int i = 0; i<p.size(); i++) {
			if(p[i]=='R') {
				int temp = start;
				start = end;
				end = temp;
			} else if(p[i]=='D') {
				if(n) {
					if(start>=end) {
						start--;
					} else {
						start++;
					}
					n--;
				} else {
					can = false;
				}
			}

		}
		if(can) {
			cout<<"[";
			if(start>=end) {
				for(int i = start-1; i>=end; i--) {
					cout<<num[i];
					if(i!=end) {
						cout<<",";
					}
				}
			} else {
				for(int i = start; i<end; i++) {
					cout<<num[i];
					if(i!=end-1) {
						cout<<",";
					}
				}
			}
			cout<<"]\n";
		} else {
			cout<<"error\n";
		}
	}
	return 0;
}