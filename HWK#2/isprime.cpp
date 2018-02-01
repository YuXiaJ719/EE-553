#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(unsigned long long p);

int main(){
	unsigned long long p;
	cin >> p;

	if(isPrime(p))
		cout << "The input is prime number." << endl;
	else
		cout << "The input is not prime number." << endl;

	return 0;
}

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