#include <vector>
//BOJ #15596
long long sum(std::vector<int>& a) {
    long long s = 0;
    for(int i:a) {
        s+=i;
    }
    return s;
}
