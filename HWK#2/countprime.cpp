#include <iostream>
#include <cmath>
using namespace std;


bool isPrime(unsigned long long p){
	bool result = true;

	if(p == 1){
		result = false;
	}

	for(long long i = 2; i <= pow(p, 0.5); i++){
		if(p % i == 0){
			result = false;
			break;
		}
	}
	return result;
}

int countPrime(unsigned long long a, unsigned long long b){
	int count = 0;

	for(int i = a; i <= b; i++){
		if(isPrime(i)){
			count++;
		}
	}
	return count;
}

int main(){
	unsigned long long a, b;
	cin >> a >> b;

	if(a < b)
		cout << countPrime(a, b) << endl;
	else
		cout << countPrime(b, a) << endl;
	
	return 0;
}





