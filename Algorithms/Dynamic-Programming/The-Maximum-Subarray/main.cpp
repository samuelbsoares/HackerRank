#include <vector>
#include <iostream>

using namespace std;

int maxContiguous( vector< int > m ) {
    int maxSoFar = m.at(0);
    int maxToHere = max_so_far;
    for( vector< int >::iterator it = m.begin() + 1; it < m.end(); ++it ) {
        maxToHere = ( *it > *it + maxToHere ) ? *it : *it + maxToHere;
        maxSoFar = ( maxToHere > maxSoFar ) ? maxToHere : maxSoFar;
    }
    return maxSoFar;
}

int main() {
    int T( 0 );
    cin >> T;
    while( T-- ) {
        int N( 0 ), k( 0 ), m( 0 );
        cin >> N;
        vector< int > n( 0 );
        for( ; N > 0; --N ) {
            cin >> k;
            if( k > 0 )
                m += k;
            n.push_back( k );
        }
        int maxC = maxContiguous( n );
        if (maxC < 0) { m = maxC; };
        cout << maxC << " " << m << "\n";
    }
    return 0;
}
