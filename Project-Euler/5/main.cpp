#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(long result, int n){
    for (int i = n; i > 0; --i){
        if (result % i != 0){
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        long n;
        cin >> n;
        long result;
        result = 1;
        while (!check(result, n)){
            result += 1;
        }
        cout << result << "\n";
    }
    
    return 0;
}

