#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const unsigned long limit = 5000000;
    int count = 0;
    bool isComposit[limit];
    vector<long> primes;
    long upperlimit = (long)sqrt(limit);

    int T;
    cin >> T;
    int n[T];
    int max_n = 0;
    for (int q = 0; q<T; q++) {
        cin >> n[q];
        max_n = max_n < n[q] ? n[q] : max_n;
    }

    for (long i = 2; i <= limit; ++i) {
        if (!isComposit[i]) {
            count += 1;
            primes.push_back(i);
            if (count > max_n) { break; }
            for (long j = i * i; j <= limit; j += i) {
                 if (!isComposit[j]) isComposit[j] = true;
            }
        }
    }
    for (int q = 0; q<T; q++) {
        cout << primes[n[q]-1] << endl;
    }
    
    return 0;
}
