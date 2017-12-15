#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long collatz( long long num, long t ) {
    if( num <= 1 )
        return 1;
    if( num % 2 == 0 )
        return 1 + collatz( num / 2, t + 1 );
    else
        return 1 + collatz( 3 * num + 1, t + 1 );
}

int main() {
    unsigned int T;
    cin >> T;
    long long maxN(0);
    long long m[ T ];
    for( unsigned int t = 0; t < T; ++t ) {
        cin >> m[ t ];
        maxN = max( maxN, m[ t ] );
    }
    vector< long > ans( maxN + 1, 1 ), c( maxN + 1, 0);
    for( long i = 1; i <= maxN; ++i ) {
        long col = collatz( i, 0 );
        if( col >= c[ i - 1 ] ) {
            c[ i ] = col;
            ans[ i ] = i;
        }
        else {
            c[ i ] = c[ i - 1 ];
            ans[ i ] = ans[ i - 1 ];
        }
    }
    for( unsigned int t = 0; t < T; ++t ) {
        cout << ans[ m[ t ] ] << endl;
    }
    return 0;
}
