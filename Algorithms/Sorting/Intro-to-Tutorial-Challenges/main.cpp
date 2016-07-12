#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int F;
    cin>>F;
    int n, k(0), ans(0);
    cin>>n;

    while(n--) {
        cin>>k;
        if(F==k){
            cout<<ans;
            return 0;
        }
        ++ans;
    }

    return 0;
}
