#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T(0), A(0), B(0), sqr_A(0), sqr_B(0);
    cin >> T;
    
    for(;T;--T) {
        cin >> A >> B;
        int ans(0);
        sqr_A = int(ceil(sqrt(A)));
        sqr_B = int(floor(sqrt(B)));
        for(int i=sqr_A; i <= sqr_B; ++i) {
            ++ans;
        }
        cout << ans << endl;
    }
    
    return 0;
}
