#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    const int LIMIT = 3000;
    vector< long long > answer( LIMIT, -1 );
    
    for( int a = 1; a < LIMIT; ++a ) {
        for( int b = a; b < LIMIT; ++b ) {
            double dC = sqrt( a * a + b * b );
            int iC = static_cast< int >( dC );
            if( ceil( dC ) == static_cast< int >( dC ) && ( a + b + iC <= 3000 ) )
                    answer[ a + b + iC ] = max( answer[ a + b + iC ], static_cast< long long >( a * b * iC ) );
        }
    }

    int T;
    cin >> T;
    while( T-- ) {
        int N;
        cin >> N;
        cout << answer[N] << endl;
    }
    
    return 0;
}
