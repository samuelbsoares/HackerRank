#include <vector>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    long n[ T ];
    long limit = 0;
    for( int t = 0; t < T; ++t ) {
        cin >> n[ t ];
        limit = n[ t ] > limit ? n[ t ] : limit;
    }
    vector< long > isprime( limit + 1, 1 );
    long sumprime = 0;
    for( long i = 2; i < limit + 1; ++i ) {
        if( isprime[ i ] ) {
            sumprime += i;
            isprime[ i ] = sumprime;
            for( long j = i * i; j < limit + 1; j += i )
                isprime[ j ] = 0;
        }
    }
    for( int t = 0; t < T; ++t ) {
        long m = n[ t ];
        while( isprime[m] == 0 )
            --m;
        cout << isprime[m] << endl;
    }
    return 0;
}
