#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_contiguous(vector<int> m) {
    int max_so_far = m.at(0);
    int max_ending_here = max_so_far;
    for (vector<int>::iterator it = m.begin() + 1; it < m.end(); it++) {
        max_ending_here = (*it > *it + max_ending_here) ? *it : *it + max_ending_here;
        max_so_far = (max_ending_here > max_so_far) ? max_ending_here : max_so_far;
    };
    
    return max_so_far;
};

int main() {
    int T(0);
    cin >> T;
    
    for (; T > 0; T--) {
        int N(0), k(0), m(0);
        cin >> N;
        vector<int> n(0);
        for (; N > 0; N--) {
            cin >> k;
            if (k>0) { m += k; };
            n.push_back(k);
        };
        int max_c = max_contiguous(n);
        if (max_c < 0) { m = max_c; };
        cout << max_c << " " << m << "\n";
    };
    
    return 0;
}
