#include <iostream>
#include <cmath>
using namespace std;
//BOJ #2909

int main() {
    int c, k;
    cin >> c >> k;
    k = pow(10, k);
    if (c % k < k / 2) {
        cout << (c / k) * k;
    }
    else {
        cout << (c / k + 1) * k;
    }
    return 0;
}