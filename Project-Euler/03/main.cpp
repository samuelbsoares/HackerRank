#include <cmath>
#include <iostream>

using namespace std;

bool isPrime( long long x ) {
    if( ( x == 2 ) || ( x == 3 ) )
        return true;
    if( ( x == 1 ) || ( x % 2 == 0 ) )
        return false;
    for( long long i = 3; i <= sqrt( x ) ; i += 2) {
        if( x % i == 0 )
            return false;
    }
    return true;
}

int main() {
    int x;
    cin >> x;    
    for( int i = 0; i < x; ++i ) {
        long long n;
        cin >> n;
        long long largestFactor = 1;
        for( long long k = 1; k <= sqrt( n ); ++k ) {
            if( n % k == 0 ) {
                if( isPrime( k ) )
                    largestFactor = max( k, largestFactor );
                if( isPrime( n / k ) )
                    largestFactor = max( largestFactor, n / k );
            }
        }
        cout << largestFactor << endl;
    }    
    return 0;
}
