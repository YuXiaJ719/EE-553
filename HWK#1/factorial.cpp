/*
 * Author: Yu Xia
 * Created on 1/23/2018
*/

#include <iostream>
using namespace std;

//int factorial(long n){
//    if (n == 1)
//        return 1;
//    else
//        return n * factorial(n - 1);
//}

//int main(){
//    long n;
//    cin >> n;
//    cout << factorial(n) << endl;
//    return 0;
//}

int main(){
    int n;
    cin >> n;
    long long factorials = 1;
    for(int i = 1; i <= n; i++){
        factorials *= i;
    }

    cout << factorials << endl;
}


