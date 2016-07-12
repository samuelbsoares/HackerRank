#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int s(1);
        for(int k(0); k<n; k++) {
            s += (k % 2 == 0) ? s : 1;
        }
        cout << s << endl;
    }
    return 0;
}
