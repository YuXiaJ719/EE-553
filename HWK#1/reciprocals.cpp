/*
 * Author: Yu Xia
 * Created on 1/23/2018
*/

#include <iostream>
using namespace std;

int main(){
    float sum1;
    float sum2;

    for (float i = 1; i <= 100.0; i++){
        sum1 += 1.0f / i;
    }
    for (float i = 0; i < 100.0; i++){
        sum2 +=  1.0f / (100 - i);
    }
    cout << "###Sum using float type###" << endl;
    cout << "Sum1 is " << sum1 << endl;
    cout << "Sum2 is " << sum2 << endl;
    cout << "Sum1 - Sum2 is " << sum1 - sum2 << endl;

    double sum3;
    double sum4;

    for (double i = 1.0; i <= 100.0; i++){
        sum3 += 1.0 / i;
    }
    for (double i = 0; i < 100.0; i++){
        sum4 += 1.0 / (100 - i);
    }

    cout << "###Sum using double type###" << endl;
    cout << "Sum3 is " << sum3 << endl;
    cout << "Sum4 is " << sum4 << endl;
    cout << "Sum3 - Sum4 is " << sum3 - sum4 << endl;
    return 0;
}