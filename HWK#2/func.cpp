#include <iostream>
using namespace std;

double fact(double n){

	if(n <= 1)
		return 1;

	double prod = 1;

	for(double i = 1; i <= n; i++){
		prod *= i;
	}

	return prod;
}

double fact2(double n){
	if(n <= 1)
		return 1;
	else
		return n * fact2(n - 1);
}

double fibo(int n){
	double pre = 0;
	double now = 1;
	double temp;

	if(n == 1 or n == 2)
		return 1;
	for(int i = 1; i <= n - 1; i++){
		temp = now;
		now = pre + now;
		pre = temp;
	}

	return now;
}

double fibo2(int n){
	if(n == 1 or n == 2){
		return 1;
	}else{
		return fibo2(n - 1) + fibo(n - 2);
	}
}

double choose(int n, int r){
	double numerator = 1;
	double denominator = fact2(r);

	for(int i = n - r + 1; i <= n; i++){
		numerator *= i;
 	}
 	return numerator / denominator;
}

double choose2(int n, int r){
	return fact2(n) / (fact2(r)*fact2(n - r));
}

int main() {
  cout << fact(5) << ' ' << fact2(5) << '\n';
  cout << fact(15) << ' ' << fact2(15) << '\n';
  cout << fibo(5) << ' ' << fibo2(5) << '\n';
  cout << fibo(13) << ' ' << fibo2(13) << '\n';
  cout << choose(52, 6) << '\n';
  return 0;
}




