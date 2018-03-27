#include <iostream>
#include <iomanip>
#include "Matrix.hh"
using namespace std;

Matrix operator +(Matrix left, Matrix right){
    if(left.rows != right.rows || left.cols != right.cols){
        cout << "Dimension is not match: " << '(' << left.rows << ',' << left.cols << ')' << ',' << '(' << right.rows << ',' << right.cols << ')';
        return Matrix(0, 0, 0);
    }
    int size = left.rows * right.cols;
    Matrix res(left.rows, left.cols);
    for(int i = 0; i < size; i++)
        res.mat[i] = left.mat[i] + right.mat[i];
    
    return res;
}

Matrix operator -(Matrix left, Matrix right){
    if(left.rows != right.rows || left.cols != right.cols){
        cout << "Dimension is not match: " << '(' << left.rows << ',' << left.cols << ')' << ',' << '(' << right.rows << ',' << right.cols << ')';
        return Matrix(0, 0, 0);
    }
        
    int size = left.rows * right.cols;
    Matrix res(left.rows, left.cols);
    for(int i = 0; i < size; i++)
        res.mat[i] = left.mat[i] - right.mat[i];
    
    return res;
}

Matrix operator *(Matrix left, Matrix right){
    if(left.cols != right.rows)
        return Matrix(0, 0, 0);
    
    Matrix res(left.rows, right.cols);
    
    for(int i = 0; i < left.rows; i++){
        for(int j = 0; j < right.cols; j++){
            for(int k = 0; k < left.cols; k++)
                res.mat[i*left.rows + j] += left.mat[i*left.cols + k] * right.mat[k*right.cols + j];
        }
    }

    return res;
}

ostream& operator << (ostream& s, Matrix m){
    for(int i = 0; i<m.rows; i++){
        for(int j = 0; j<m.cols; j++)
            cout << setw(5) << m.mat[i*m.cols + j] << setw(3) << " ";
        cout << '\n';
    }
    
    return s;
}

double& Matrix::operator ()(int i, int j){
    return mat[i*cols + j];
}

