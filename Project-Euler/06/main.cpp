#include <iostream>

using namespace std;

long sqrOfSums( int n ) {
    long s(0);
    for( int i = n; i > 0; --i )
        s += i;
    return s * s;
}

long sumOfSqrs( int n ) {
    long s(0);
    for( int i = n; i > 0; --i)
        s += i * i;
    return s;
}

int main() {
    int T;
    cin >> T;
    while( T-- ) {
        int n;
        cin >> n;
        cout << sqrOfSums(n) - sumOfSqrs(n) << "\n";
    }
    return 0;
}
