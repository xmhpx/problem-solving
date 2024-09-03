// Matrix
// copy the Matrix class and the FastMod class.
// instantiate a FastMode with b = mod.
// instantiate as many Matrix as needed with _n = maxSize.
// use operators [=, +, *, ^] and I().

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

class Matrix {
  public:
    FastMod fm;
	int n;
	vector<vector<int>> mat;
	Matrix(int _n) : n(_n), mat(_n, vector(_n, 0)) {}

	void I(){
		mat = vector(n, vector(n, 0));
		for(int i = 0; i < n; i++)mat[i][i] = 1;
	}

	Matrix operator= (const Matrix &b){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				mat[i][j] = b.mat[i][j];
			}
		}
		return *this;
	}

	Matrix operator+ (const Matrix &b){
		Matrix r(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				
				r.mat[i][j] = fm.reduce(mat[i][j] + b.mat[i][j]);
			}
		}
		return r;
	}

	Matrix operator* (const Matrix &b){
		Matrix r(n);
        for(int i = 0; i < n; i++){
		    for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
					r.mat[i][k] = fm.reduce(r.mat[i][k] + mat[i][j]*1ll*b.mat[j][k]);
				}
			}
		}
		return r;
	}

	Matrix operator^ (unsigned long long p){
		Matrix r(n), b(n);
		r.I();
		b = *this;
		while(p){
			if(p&1){
				r = r*b;
			}
			b = b*b;
			p >>= 1;
		}
		return r;
	}
};

signed main(){}