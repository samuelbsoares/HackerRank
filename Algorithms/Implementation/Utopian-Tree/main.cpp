#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for( int i = 0; i < T; ++i){
        int n;
        cin >> n;
        int s( 1 );
        for( int k = 0; k < n; ++k ) {
            s += ( k % 2 ) ? 1 : s;
        }
        cout << s << endl;
    }
    return 0;
}
