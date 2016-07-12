#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//helper function to print vector of vectors ints
void print_v(vector<vector<int>> layers_vector) {
    for(int i = 0; i < layers_vector.size(); ++i) {
        for(int j = 0; j < layers_vector[i].size(); ++j) {
            cout << layers_vector[i][j] << " ";
        }
        cout << endl;
    }
}

//helper function to print vector of ints
void print_v(vector<int> layers_vector) {
    for(int i = 0; i < layers_vector.size(); ++i) {
        cout << layers_vector[i] << " ";
    }
    cout << endl;
}

//function to rotate right the vector of vectors
void rotate_layers(vector<vector<int>>& layers, int R) {
    //rotates right by R % layers[layer].size()
    //avoiding unnecessary movements
    for(int layer = 0; layer < layers.size(); ++layer) {
        rotate(layers[layer].rbegin(), layers[layer].rbegin() + (R % layers[layer].size()), layers[layer].rend());
    }
}

vector<vector<int>> read_layers(const vector<vector<int>>& matrix, int rows, int columns) {
    int total_layers = min(rows, columns) / 2;
    vector<vector<int>> layers_vector;
    
    //iterates all layers
    for(int layer = 0; layer < total_layers; ++layer) {
        vector<int> aux;
        //pushes left rows-1 values
        for(int off = 0; off < rows - 1; ++off) {
            aux.push_back(matrix[off+layer][layer]);
        }
        //pushes bottom columns-1 values
        for(int off = 0; off < columns - 1; ++off) {
            aux.push_back(matrix[layer+rows-1][layer+off]);
        }
        //pushes right rows-1 values
        for(int off = layer + rows - 1; off > layer; --off) {
            aux.push_back(matrix[off][layer+columns-1]);
        }
        //pushes top columns-1 values
        for(int off = layer + columns - 1; off > layer; --off) {
            aux.push_back(matrix[layer][off]);
        }
        //removes 2 elements for the new layer
        --(--rows);
        --(--columns);
        layers_vector.push_back(aux);
    }
    
    return layers_vector;
}

vector<vector<int>> layers_to_matrix(vector<vector<int>>& layers, int M, int N) {
    int total_layers = min(M, N) / 2;
    vector<vector<int>> matrix(M, vector<int>(N, 0));
    
    //iterates all layers
    for(int layer = 0; layer < total_layers; ++layer) {
        //pushes left rows-1 values
        vector<int>::iterator it = layers[layer].begin();
        for(int off = 0; off < M - 1; ++off) {
            matrix[off+layer][layer] = *it;
            it++;
        }
        //pushes bottom columns-1 values
        for(int off = 0; off < N - 1; ++off) {
            matrix[layer+M-1][layer+off] = *it;
            it++;
        }
        //pushes right rows-1 values
        for(int off = layer + M - 1; off > layer; --off) {
            matrix[off][layer+N-1] = *it;
            it++;
        }
        //pushes top columns-1 values
        for(int off = layer + N - 1; off > layer; --off) {
            matrix[layer][off] = *it;
            it++;
        }
        //removes 2 elements for the new layer
        --(--M);
        --(--N);
    }
    return matrix;
}

int main() {

    //read parameters
    int M(0), N(0), R(0);
    cin >> M >> N >> R;

    //initialize vectors
    vector<vector<int>> matrix(0);
    vector<int> aux(N, 0);
    
    //read the matrix
    for(int m = 0; m < M; ++m) {
        for(int n = 0; n < N; ++n) {
            cin >> aux[n];
        }
        matrix.push_back(aux);
    }
    vector<vector<int>> layers_vector = read_layers(matrix, M, N);
    rotate_layers(layers_vector, R);
    matrix = layers_to_matrix(layers_vector, M, N);
    print_v(matrix);
    return 0;
}
