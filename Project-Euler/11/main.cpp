#include <iostream>

int main() {
    const int M = 20;
    int i, j;
    long long int maxN( 0 );
    int A[ M ][ M ];
    for( i = 0; i < M; ++i) {
        for(j=0;j<20;j++)
            std::cin >> A[ i ][ j ];
    }
    for( i = 0; i < 20; ++i) {
        long long int h = 1, v = 1, d = 1, dd = 1;
        for( j = 0; j < M; ++j) {
            if( ( i + 3 ) < M )
                v = A[ i ][ j ] * A[ i + 1 ][ j ] * A[ i + 2 ][ j ] * A[ i + 3 ][ j ];
            if( ( j + 3 ) < M )
                h = A[ i ][ j ] * A[ i ][ j + 1 ] * A[ i ][ j + 2 ] * A[ i ][ j + 3 ];
            if( ( ( i + 3 ) < M ) && ( ( j + 3 ) < 20 ) )
                d = A[ i ][ j ] * A[ i + 1 ][ j + 1 ] * A[ i + 2 ][ j + 2 ] * A[ i + 3 ][ j + 3 ];            
            if( i > 2 && j < 17)
                dd = A[ i ][ j ] * A[ i - 1 ][ j + 1 ] * A[ i - 2 ][ j + 2 ] * A[ i - 3 ][ j + 3 ];
            maxN = std::max( maxN, std::max ( std::max( v, h ), std::max( d, dd ) ) );
        }  
    }
    std::cout << maxN;
}
