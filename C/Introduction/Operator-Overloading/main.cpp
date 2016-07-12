#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Begin of code
class Matrix {
    public:
        vector<vector<int> > a;
        Matrix operator+ (const Matrix& m) {
            Matrix ans;
            for(int i=0; i < m.a.size(); ++i) {
                vector<int> aux;
                for(int j=0; j < m.a[i].size(); ++j) {
                    int k = m.a[i][j] + this->a[i][j];
                    aux.push_back(k);
                };
                ans.a.push_back(aux);
            };
            return ans;
        };
};
//End of code

// Code provided by HackerRank
int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
