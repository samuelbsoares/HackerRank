from sys import stdin
from math import factorial

def ways( n, m ):
    return ( factorial( n + m ) / ( factorial( n ) * factorial( m ) ) )

times = int( stdin.readline() )

for i in xrange( times ):
    x = map( int, stdin.readline().split() )
    print( int( ways( x[ 0 ], x[ 1 ] ) % ( 10 ** 9 + 7 ) ) )
