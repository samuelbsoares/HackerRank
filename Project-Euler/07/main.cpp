#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    const unsigned long LIMIT = 5000000;
    int count = 0;
    bool isComposit[ LIMIT ];
    vector< long > primes;
    long upperlimit = (long) sqrt( LIMIT );

    int T;
    cin >> T;
    int n[ T ];
    int max_n = 0;
    for( int q = 0; q < T; ++q ) {
        cin >> n[ q ];
        max_n = max_n < n[ q ] ? n[ q ] : max_n;
    }

    for( long i = 2; i <= LIMIT; ++i ) {
        if( !isComposit[ i ] ) {
            count++;
            primes.push_back(i);
            if( count > max_n )
                break;
            for( long j = i * i; j <= LIMIT; j += i) {
                 if ( !isComposit[j] )
                     isComposit[j] = true;
            }
        }
    }
    for( int q = 0; q < T; ++q )
        cout << primes[ n[ q ] - 1 ] << endl;
    return 0;
}
