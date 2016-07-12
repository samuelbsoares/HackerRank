#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int limit = 1000000;
const int M = 100000;

int main() {
    
    int T(0), maxN(0);
    cin >> T;
    int N[T];
    for (int t = 0; t < T; ++t) {
        cin >> N[t];
        maxN = (N[t] > maxN) ? (N[t]) : (maxN);
    }
    
	vector<bool> sieve(limit,false);
	vector<int> prime;
	vector<int> ans(M);
	
	for(int i = 2; i <= limit; ++i) {
		if (!sieve[i]) {
            prime.push_back(i);
			for (int b = i + i; b <= limit; b += i)
                sieve[b] = true;
		}
	}

	sieve[1] = true;

	for (int i = 1; i <= M ; ++i) {
		int x = i * (i + 1);
        int num = 1;
        x /= 2;
        int to = ceil(sqrt(static_cast<double>(x)));
        for (int j = 0; prime[j] <= to ; ++j) {
            int y = 0;
            while (x % prime[j] == 0) {
                x /= prime[j];
                ++y;
            }
            if (y != 0)
                num *= y + 1;
        }
        if (x != 1)
            num *= 2;
        ans[i] = num;
        if (ans[i] > maxN) break;
    }

	for (int n = 0; n < T; ++n) {
		for (int i = 1; i <= M; ++i)
			if (ans[i] > N[n]) {
				cout << (i * (i + 1)) / 2 <<endl;
				break;
			}
	}
	
	return 0;
}
