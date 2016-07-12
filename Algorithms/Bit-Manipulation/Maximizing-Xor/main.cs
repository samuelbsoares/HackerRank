using System;
using System.Collections.Generic;
using System.IO;

class Solution {

    static int maxXor(int l, int r) {
        int max = 0;
        int xor = 0;
        for (int i=l; i<=r; i++){
            for (int x=i+1;x<=r; x++){
                xor = i^x;
                if (xor>max) max = xor;
            }
        }
        return max;
    }

    static void Main(String[] args) {
        int res;
        int _l;
        _l = Convert.ToInt32(Console.ReadLine());
        
        int _r;
        _r = Convert.ToInt32(Console.ReadLine());
        
        res = maxXor(_l, _r);
        Console.WriteLine(res);
        
    }
}