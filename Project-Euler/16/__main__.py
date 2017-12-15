from sys import stdin

def getPower( n ):
    a = list( str( 2 ** n ) )
    return sum( [ int( i ) for i in a ] )

times = int( stdin.readline() )

for i in xrange( times ):
    print( getPower( int( stdin.readline() ) ) )
