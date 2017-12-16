#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 10000000 + 10;
const int MAXP = 664579 + 10;

vector< bool > isPrime(MAXN, true);
vector< int > prime(MAXP);
int primeNum;

void sieve() {
    primeNum = 1;
    isPrime[ 0 ] = isPrime[ 1 ] = false;
    prime[ 0 ] = 2;
    for (int i = 4; i < MAXN; i += 2 ) {
        isPrime[ i ] = false;
    }
    for( int i = 3; i < MAXN; i += 2 ) {
        if( isPrime[ i ] ) {
            prime[ primeNum++ ] = i;
            int inc = i << 1;
            for( int j = i + inc; j < MAXN; j += inc )
                isPrime[ j ] = false;
        }
    }
}

bool checkPrime(long long x) {
    if( x < MAXN )
        return isPrime[ x ];
    
    int last = sqrt( x );
    for( int i = 0; i < primeNum && prime[ i ] <= last; ++i) {
        if( x % prime[ i ] == 0 )
            return false;
    }
    return true;
}


int main() {
    
    long long T, N;
    sieve();

    long long sum[ MAXP ];
    sum[ 0 ] = 0;
    
    for( int i = 0; i < primeNum; ++i )
        sum[ i + 1 ] = sum[ i ] + prime[ i ];
    cin >> T;
    while( T-- ) {
        cin >> N;
        int left = 0, right = primeNum;
        int first = primeNum - 1;
        while(left <= right) {
            int mid = ( left + right ) >> 1;
            if( sum[ mid ] == N ) {
                first = mid;
                break;
            }
            else if( sum[ mid ] < N )
                left = mid + 1;
            else {
                first = min( first, mid );
                right = mid - 1;
            }
        }
        int longest = -1;
        long long ans;
        for( int i = 0; i < 30; ++i ) {
            for( int j = first + 10; j >= i; --j ) {
                long long val = sum[ j ] - sum[ i ];
                if( val <= N && checkPrime( val ) ) {
                    if(j - i > longest ) {
                        longest = j - i;
                        ans = val;
                    }
                    else if( j - i == longest )
                        ans = min(ans, val);
                    break;
                }
            }
        }
        cout << ans << ' ' << longest << endl;
    }
    return 0;
}
