#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long sqr_of_sums(int n) {
    long s(0);
    for (int i = n; i > 0; i--) { s += i; }
    return pow(s, 2);
}

long sum_of_sqrs(int n) {
    long s(0);
    for (int i = n; i > 0; i--) { s += pow(i, 2); }
    return s;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << sqr_of_sums(n) - sum_of_sqrs(n) << "\n";
    }
    
    return 0;
}
