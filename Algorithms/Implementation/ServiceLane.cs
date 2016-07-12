using System;
using System.Collections.Generic;
using System.IO;

class Solution {

   static int veiculo(int i, int j, int[] w){
        int menor = 3;
        for (int x=i; x<=j; x++){
            int aux = w[x];
            if (aux==1){
                return 1;
            }
            else if (aux<menor){
                menor = aux;
            }
        }
        return menor;
    }
    
    static void Main(String[] args) {
        int N;
        int T;
        int _i;
        int _j;
        int[] width;
        String[] aux;
        
        String lidos = Console.ReadLine();
        String[] lidos_separados = lidos.Split(' ');
        N = Convert.ToInt32(lidos_separados[0]);
        T = Convert.ToInt32(lidos_separados[1]);
        String width_juntos = Console.ReadLine();
        aux = width_juntos.Split(' ');
        width = new int[N];

        for (int y=0;y<N;y++)
            width[y] = Convert.ToInt32(aux[y]);

        for (int x=0; x<T; x++){
            String casos = Console.ReadLine();
            String[] casos_sep = casos.Split(' ');
            _i = Convert.ToInt32(casos_sep[0]);
            _j = Convert.ToInt32(casos_sep[1]);
            Console.WriteLine(veiculo(_i, _j, width));
        }
    }
}
