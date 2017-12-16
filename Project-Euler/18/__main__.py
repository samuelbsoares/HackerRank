from sys import stdin

def nat( n ):
    if n <= 1: return 1
    return n + nat( n-1 )

T = int( stdin.readline().rstrip("\n") )
for dummy in range(T):
    mat = []
    N = int( stdin.readline().rstrip("\n") )
    if N == 1:
        print( int( stdin.readline().rstrip("\n") ) )
        continue
    for i in range(N):
        mat.append( list( map( int, stdin.readline().rstrip("\n").split(" ") ) ) );
    for row in range( len(mat) - 1, 0, -1 ):
        for col in range( row ):
            mat[ row - 1 ][ col ] += max( mat[ row ][ col ], mat[ row ][ col + 1 ] )
    print( mat[ 0 ][ 0 ] )
