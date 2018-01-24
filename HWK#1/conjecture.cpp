/*
 * Author: Yu Xia
 * Created on 1/23/2018
*/

#include <iostream>
using namespace std;

int main (){
    int n;
    cin >> n;
    while (n != 1) {
        if (n % 2 == 0){
            n /= 2;
        }else {
            n = n * 3 + 1;
        }
        cout << n << endl;
    }
    return 0;
}
