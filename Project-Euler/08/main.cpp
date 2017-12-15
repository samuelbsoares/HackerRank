#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long mult( string sub ) {
    long ans = 1;
    for( int i = 0; i < sub.size(); ++i )
        ans *= ( sub[ i ] - '0' );
    return ans;
}

int main() {
    int T;
    cin >> T;
    while( T-- ) {
        short K;
        int N;
        cin >> K >> N;
        string strnumber;
        cin >> strnumber;
        vector< long > multiples;
        
        for( int i = 0; i < K - N; ++i )
            multiples.push_back( mult( strnumber.substr( i, N ) ) );
        
        cout << *max_element( multiples.begin(), multiples.end() ) << endl;
    }
    return 0;
}
