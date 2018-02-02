#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(unsigned long long p);

int main(){
	unsigned long long p;
	cin >> p;

	if(isPrime(p))
		cout << "This number is prime." << endl;
	else
		cout << "The number is not prime." << endl;

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