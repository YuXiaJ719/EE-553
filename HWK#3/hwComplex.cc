/*
	Author: Yu Xia
	Date: 2/10/2018
 */
#include <iostream>
using namespace std;

class Complex{
private:
	double real, imag;

public:
	Complex(double a, double b){
		real = a;
		imag = b;
	}

	void print() const{
		cout << '(' << real << ',' << imag << ')' << '\n';
	}

	Complex add(Complex rhs) const{
		return Complex(real + rhs.real, imag + rhs.imag);
	}

	Complex operator +(Complex roperand) const{
		return Complex(real + roperand.real, imag + roperand.imag);
	}

	Complex operator -() const{
		return Complex(-real, -imag);
	}

	Complex operator -(Complex rhs) const{
		return Complex(real - rhs.real, imag - rhs.imag);
	}

};


int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using the first syntax we discussed
	c.print(); // should print the following to cout: (1.5,2.0)
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	Complex e = -d;
	e.print();
}
