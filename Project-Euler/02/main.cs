using System;
using System.Collections.Generic;
using System.IO;

class Solution {

    static long evenFibSum( long n ){
        long fib = 8;
        long nextFib = 13;
        long aux = 0;
        long sum = 10;
        while( nextFib < n ) {
            if( nextFib % 2 == 0 ){
                sum = sum + nextFib;
            }
            aux = nextFib;
            nextFib = fib + nextFib;
            fib = aux;
        }
        return sum;
    }

    static void Main( String[] args ) {
        int n = Convert.ToInt32( Console.ReadLine() );
        for( int x = 0 ; x < n ; x++ ) {
            long f = Convert.ToInt64( Console.ReadLine() );
            Console.WriteLine( evenFibSum(f) );
        }
    }
}
