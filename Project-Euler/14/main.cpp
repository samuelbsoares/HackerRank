#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long collaz(long long num, long t) {
    if (num <= 1) return 1;
    if (num % 2 == 0)
        return 1 + collaz(num / 2, t + 1);
    else
        return 1 + collaz(3 * num + 1, t + 1);
}

int main() {
    unsigned int T;
    cin >> T;
    long long mx(0);
    long long m[T];
    
    for (unsigned int t = 0; t < T; ++t){
        cin >> m[t];
        mx = max(mx, m[t]);
    }

    vector<long> ans(mx + 1, 1), c(mx + 1, 0);

    for (long i = 1; i <= mx; ++i) {
        long col = collaz(i, 0);
        if (col >= c[i-1]) {
            c[i] = col;
            ans[i] = i;
        }
        else {
            c[i] = c[i - 1];
            ans[i] = ans[i - 1];
        }
    }

    for (unsigned int t = 0; t < T; ++t) {
        cout << ans[m[t]] << endl;
    }

    return 0;
}
