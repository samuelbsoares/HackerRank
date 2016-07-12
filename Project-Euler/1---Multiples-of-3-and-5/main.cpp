#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long divisible(long long n, int t) {
	return (t + (n - 1) / t * t) * ((n - 1) / t) / 2;
}

int main() {

	int T;
	cin >> T;

	while (T > 0) {
		unsigned long n;
		cin >> n;
		cout << divisible(n, 3) + divisible(n, 5) - divisible(n, 15) << endl;
        T--;
	}

	return 0;
}
