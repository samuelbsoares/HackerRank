using System;
using System.Collections.Generic;
using System.IO;

class Solution {

    static string isFib(long number){
        long aux;
        long atual = 1;
        long ultimo = 0;
        while (atual < number){
            aux = ultimo;
            ultimo = atual;
            atual = aux + ultimo;            
        }
        if (atual == number)
            return "IsFibo";
        else
            return "IsNotFibo";
    }

    static void Main(String[] args) {
        int x = Convert.ToInt32(Console.ReadLine());
        for (int i=0; i < x; i++){
            long n = Convert.ToInt64(Console.ReadLine());
            Console.WriteLine(isFib(n));
        }
    }
}
