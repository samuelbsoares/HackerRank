#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Simplified bigint
struct bigInt {
	vector<int> a;
    
	bigInt() {
		a.push_back(0);
	}
	bigInt( int x ) {
		if( x == 0 )
			a.push_back( 0 );
		while( x != 0) {
			a.push_back( x % 10 );
			x = x / 10;
		}
	}
	void operator += ( const bigInt & b ) {
		vector<int> x, y, z;
		x = a;
		y = b.a;
		int n = x.size();
		int m = y.size();
		if( n < m ) {
			for( int i = 0; i < m - n; ++i )
				x.push_back( 0 );
        }
        else {
			for( int i = 0; i < n - m; ++i )
				y.push_back( 0 );
        }
		int h = 0;
		for( int i = 0; i < x.size(); ++i ) {
			z.push_back( x[ i ] + y[ i ] + h );
			h = z[ i ] / 10;
			z[ i ] %= 10;
		}
		if( h == 1 )
			z.push_back( 1 );
		while( z[ z.size() - 1 ] == 0 )
			z.pop_back();
		a = z;
	}
};

istream & operator >> (istream & in, bigInt & big) {
	string s;
	big.a.clear();
	in >> s;
	for( int i = s.size() - 1; i >= 0; --i )
		big.a.push_back( s[ i ] - '0' );
	return in;
}

ostream & operator << (ostream & out, const bigInt & big) {
	for( int i = big.a.size() - 1; i >= 0; --i )
		out << big.a[ i ];
	return out;
}

int main() {
	bigInt a, b;
	int T;
	cin >> T;
	while( T-- ) {
		cin >> b;
		a += b;
	}
	for( int i = a.a.size() - 1; i >= a.a.size() - 10; --i )
		cout << a.a[ i ];
}
