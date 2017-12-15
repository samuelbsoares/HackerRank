#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    int limit = 3000;
    vector<long long> answer(limit, -1);
    
    for (int a = 1; a < limit; ++a) {
        for (int b = a; b < limit; ++b) {
            double dC = sqrt(a*a + b*b);
            int iC = static_cast<int>(dC);
            if (ceil(dC) == static_cast<int>(dC)) {
                if (a+b+iC <= 3000)
                    answer[a + b + iC] = max(answer[a + b + iC], static_cast<long long>(a * b * iC));
            }
        }
    }

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        cout << answer[N] << endl;
    }
    
    return 0;
}
