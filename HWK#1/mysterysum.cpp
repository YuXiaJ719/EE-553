/*
 * Author: Yu Xia
 * Created on 1/23/2018
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // Initialize two floating number to record sum(n - 1) and sum(n)
    float sum1 = 0.0f;
    float sum2 = 1.0f;
    float n = 1.0f;
    // Check the two sums. If two sums are different, then add 1 to n and add (n * n) to sum1 and sum2
    while (sum1 != sum2){
        sum1 += 1 / (n * n);
        sum2 += 1 / ((n + 1.0f) * (n + 1.0f));
        n++;
    }
//    cout << "After " << n + 1 << " loops, two results are the same." << endl;
//    cout <<  sqrtf(6 * sum1) << endl;

    float sumForward = 0.0f;
    float sumBackward = 0.0f;
    float countingNumber = 100000.0f;

    for(float i = 1.0f; i <= countingNumber; i++){
        sumForward += 1 / (i * i);
        sumBackward += 1 / ((countingNumber - i + 1) * (countingNumber - i + 1));
    }

//    cout << "The result of the square root of 6 * summing forward: " << sqrtf(6.0f * sumForward) << endl;
//    cout << "The result of the square root of 6 * summing backward: " << sqrtf(6.0f * sumBackward) << endl;
    cout << sqrtf(6.0f * sumForward) << endl;
    cout << sqrtf(6.0f * sumBackward) << endl;
}
