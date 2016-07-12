#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

long mult(string sub) {
    long ans = 1;
    for (int i = 0; i < sub.size(); ++i) {
        ans *= (sub[i] - '0');
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        short K;
        int N;
        cin >> K >> N;
        string snumber;
        cin >> snumber;
        vector<long> multiples;
        
        for (int i = 0; i < K-N; ++i) {
            multiples.push_back(mult(snumber.substr(i, N)));
        }
        cout << *max_element(multiples.begin(), multiples.end()) << endl;
    }
    
    return 0;
}
