#include <iostream>
using namespace std;

bool* Erathothenes(int n){
    bool* isPrime = new bool[n];
    
    for(int i = 0; i < n; i++){
        if(i % 2 == 0 && i > 2)
            isPrime[i] = 0;
        else
            isPrime[i] = 1;
    }
    
    for(int i = 3; i < n; i++){
        if(isPrime[i] == 1){
            for(int j = i * i; j < n; j += 2*i)
                isPrime[j] = 0;
        }
    }
    
    return isPrime;
}

int GCD(int a, int b){
    int temp;
    
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

int LCM(int a, int b){
    return a * b / GCD(a, b);
}

int Power(int x, int n){
    int prod = 1;
    while(n != 0){
        if(n % 2 != 0){
            prod = prod * x;
        }
        x = x * x;
        n = n / 2;
    }
    
    return prod;
}

int PowerMod(int x, int n, int m){
    int mod = 1;
    while(n != 0){
        if(n % 2 != 0){
            mod = (mod * x) % m;
        }
        x = (x * x) % m;
        n = n / 2;
    }
    return mod;
}

bool fermat(int p, int k){
    int a;
    for(int i = 0; i < k; i++){
        a = rand() % (p - 2) + 2;
        if(PowerMod(a, p - 1, p) != 1){
            return false;
        }
    }
    return true;
}

bool millertest(int d, int n){
    int a = rand() % (n - 3) + 2;
    int x = PowerMod(a, d, n);
    
    if(x == 1 || x == n - 1)
        return true;
    
    while(d != n - 1){
        x = (x * x) % n;
        d *= 2;
        
        if(x == 1) return false;
        if(x == n - 1) return true;
    }
    
    return false;
}

bool miller_rabin(int n, int k){
    if(n <= 1 || n == 4) return false;
    if(n <= 3) return true;
    
    int d = n - 1;
    while(d % 2 == 0)
        d /= 2;
    
    for(int i = 0; i < k; i++){
        if(millertest(d, n) == false)
            return false;
    }
    
    return true;
}


int main(){
    int a[] = {1, 2, 3, 4};
}
