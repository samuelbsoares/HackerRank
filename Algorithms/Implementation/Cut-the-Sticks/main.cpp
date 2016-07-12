#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(int arr_i = 0; arr_i < n; ++arr_i){
       cin >> arr[arr_i];
    }
    
    sort(arr.begin(), arr.end());
    
    for(auto i = arr.begin(); i < arr.end(); ++i) {
        cout << n << endl;
        --n;
        while(*i == *(i+1)) {
            ++i;
            --n;
        }
    }
    
    return 0;
}
