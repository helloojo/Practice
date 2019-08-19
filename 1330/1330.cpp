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
//BOJ #1330
typedef long long ll;
typedef unsigned long long ull;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    if(a>b) {
        cout<<'>';
    } else if(a<b) {
        cout<<'<';
    } else {
        cout<<'==';
    }
}
