#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long p(vector<int> sub) {

    long max_until = 0;

    if (sub.size() > 4) {
        for (int i = 0; i <= sub.size() - 4; ++i) {
            long ans = 1;
            for (int k = 0; k < 4; ++k) {
                ans *= sub[i + k];
                }
            max_until = max(max_until, ans);
            }
    }
    else {
        max_until = 0;
    }

    return max_until;
}

int main() {

    int matrix[20][20];

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> diag1, diag2, diag3, diag4, diag, row, col;
    long max_prod = 0;

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            row.push_back(matrix[i][j]);
            col.push_back(matrix[j][i]);
        }
        diag1.resize(i + 1);
        diag2.resize(i + 1);
        diag3.resize(i + 1);
        diag4.resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            diag1[j] = (matrix[i - j][j]);
            diag2[j] = (matrix[i - j][19 - j]);
            diag3[j] = (matrix[19 - (i - j)][j]);
            diag4[j] = (matrix[19 - j][19 - (i - j)]);
        }
        max_prod = max(max_prod, max(p(row), max(p(col), max(p(diag1), max(p(diag2), max(p(diag3), p(diag4)))))));
    }
    cout << max_prod << endl;

    return 0;
}
