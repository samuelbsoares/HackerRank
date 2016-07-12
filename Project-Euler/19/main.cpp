#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int leap(long long y){
    if(y % 400 == 0){
        return true;
    }else if(y % 100 == 0){
        return false;
    }else if(y % 4 == 0){
        return true;
    }else {
        return false;
    }
}
int ms[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days(long long y, int m){
    if(m == 2 && leap(y)) return 29;
    else return ms[m];
}
int getDays(long long y, int m){
    
    
    long long rem = y-1;
    long long yls = rem/400 + rem/4 - rem/100;
    long long ans = yls+rem;
    
    int p = 1;
    while(p < m){
        ans += days(y, p);
        p++;
    }
    return ans%7;
       
}

int get(long long y, int m, long long offset, long long ys, int ms){
    long long ans = (offset%7 == 6)?1:0;
    int tmp = ms;
    while(ys < y || tmp < m){
        offset = (offset+days(ys, tmp))%7;
        if(offset%7 == 6) ans++;
        tmp++;
        if(tmp == 13){
            tmp = 1;
            ys++;
        }
    }  
    //ans += d; 
    return ans;
}
int main() {

    int t;
    cin >> t;

    while(t--){
        long long y1, y2;
        int d1, d2, m1, m2;
        scanf("%lld %d %d %lld %d %d", &y1, &m1, &d1, &y2, &m2, &d2);
        
        if(d1 != 1){
            m1++;
            d1 = 1;
            if(m1 == 13){
                y1++;
                m1 = 1;
            }
        }
        long long before = (getDays(y1, m1)-getDays(1900, 1)+7)%7;
        long long b = get(y2, m2, before, y1, m1);
        printf("%lld\n", b);
    }
    
    return 0;
}
