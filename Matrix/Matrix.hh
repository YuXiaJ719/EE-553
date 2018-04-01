#pragma once
#include <iostream>

class Matrix{
private:
    int rows, cols;
    double* mat;

public:
    Matrix(int rows, int cols, double insertion=0) : rows(rows), cols(cols), mat(new double[rows*cols]){
        for(int i = 0; i < rows*cols;i++)
            mat[i] = insertion;
    }
    
    Matrix() : rows(0), cols(0), mat(nullptr){}
    
    Matrix(const Matrix& orig):rows(orig.rows), cols(orig.cols), mat(new double[rows*cols]){
        for(int i = 0; i < rows*cols; i++)
            mat[i] = orig.mat[i];
    }
    
    ~Matrix(){
        delete [] mat;
    }
    
    Matrix& operator =(const Matrix& orig);
    double& operator ()(int i, int j);

    friend Matrix operator +(Matrix left, Matrix right);
    friend Matrix operator -(Matrix left, Matrix right);
    friend Matrix operator *(Matrix left, Matrix right);
    friend std::ostream& operator <<(std::ostream& s, Matrix m);

};
