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
