#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h> 
using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++){
        int n(0), ans(1);
        cin >> n;
        div_t div_result;
        div_result = div(n, 10);
        while(div_result.quot > 0) {
            if(div_result.rem > 0 && n % div_result.rem == 0) {
                ans++;
            };
            div_result = div(div_result.quot, 10);
        }
        cout << ans << endl;
    }
    
    return 0;
}
