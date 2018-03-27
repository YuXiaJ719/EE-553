#include <iostream>
#include "Matrix.hh"
using namespace std;

int main(){
    Matrix m1(5, 6, 9);
    Matrix m2(6, 5, 8);
    m1(1, 2) = 1.7;
    Matrix m3 = m1 * m2;
    
    Matrix m4(4, 4, 1);
    Matrix m5(4, 4, 3);
    Matrix m6 = m4 + m5;
    
    cout << m1(3, 2) << endl;
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;
    cout << m6 << endl;
}
