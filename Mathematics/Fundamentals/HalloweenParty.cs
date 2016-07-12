using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

class Solution {

    static void Main(String[] args) {
        int T = Convert.ToInt32(Console.ReadLine());
        for (int i=0; i<T; i++){
            long K = Convert.ToInt64(Console.ReadLine());
            long d = K/2;
            Console.WriteLine(d*(d+(K%2)));
        }
    }
}
