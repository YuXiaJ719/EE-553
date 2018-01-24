/*
 * Author: Yu Xia
 * Created on 1/23/2018
*/

#include <iostream>
using namespace std;

int main(){
    float sum1;
    double sum2;

    for (float i = 1.0; i <= 100.0; i++){
        sum1 += 1.0f / i;
    }
    for (double i = 1; i <= 100.0; i++){
        sum2 += (double) 1.0 / i;
    }

    cout << "Sum1 is " << sum1 << endl;
    cout << "Sum2 is " << sum2 << endl;
    cout << "Sum1 - Sum2 is " << sum1 - sum2 << endl;

    return 0;
}