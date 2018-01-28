/*
 * Author: Yu Xia
 * Created on 1/23/2018
*/

#include <iostream>
using namespace std;

int main(){
    int GaussSum, LoopSum = 0;
    GaussSum = 100 * (100 + 1) / 2;

    for (int i = 1; i <= 100; i++){
        LoopSum += i;
    }
    cout << "The answer is: " << LoopSum << endl;
    if (GaussSum == LoopSum){
        cout << "Both summations are the same." << endl;
    }else{
        cout << "Both summations are not the same." << endl;
    }

    return 0;
}

