using System;
using System.Collections.Generic;
using System.IO;

class Solution {

    static void Main(String[] args) {
        int N;
        int K;
        long[] lista;
        N = Convert.ToInt32(Console.ReadLine());
        K = Convert.ToInt32(Console.ReadLine());
        lista = new long[N];
 
        for (int i=0; i<N; i++){
            lista[i] = Convert.ToInt64(Console.ReadLine());
        }
 
        Array.Sort(lista);
        long d = lista[N-1];
        for (int i=0; i<N-K+1; i++){
            long aux = lista[i+K-1] - lista[i];
            if (aux<d) d = aux;
        }
        Console.WriteLine(d);
    }
}
