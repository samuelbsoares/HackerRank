using System;
using System.Collections.Generic;
using System.IO;

class Solution {

    static long EvenFibSum(long n){
        long Fib = 8;
        long NextFib = 13;
        long aux = 0;
        long sum = 10;
        while (NextFib < n){
            if (NextFib%2==0){
                sum = sum + NextFib;
            }
            aux = NextFib;
            NextFib = Fib + NextFib;
            Fib = aux;
        }
        return sum;
    }

    static void Main(String[] args) {
        int n = Convert.ToInt32(Console.ReadLine());
        for (int x=0; x<n; x++){
            long f = Convert.ToInt64(Console.ReadLine());
            Console.WriteLine(EvenFibSum(f));
        }
    }
}
