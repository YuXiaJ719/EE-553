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

	friend ostream& operator <<(ostream&, Complex operand);
	friend Complex operator +(Complex loprand, Complex roprand);
	friend Complex operator -(Complex operand);
	friend Complex operator -(Complex loperand, Complex roperand);
	friend Complex add(Complex loprand, Complex roperand);

};

ostream& operator <<(ostream& s, Complex operand){
	s << '(' << operand.real << ',' << operand.imag << ')';
	return s;
}

Complex operator +(Complex loperand, Complex roperand){
	return Complex(loperand.real + roperand.real, roperand.imag + roperand.imag);
}

Complex operator -(Complex loperand, Complex roperand){
	return Complex(loperand.real - roperand.real, loperand.imag - roperand.imag);
}

Complex operator -(Complex operand){
	if(-operand.imag == 0 && -operand.real == 0)
		return Complex(operand.real, operand.imag);
	else if(operand.imag == 0)
		return Complex(-operand.real, operand.imag);
	else if(operand.real == 0)
		return Complex(operand.real, -operand.imag);
	else
		return Complex(-operand.real, -operand.imag);
}

int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using friend
	Complex d = -c; // use friend
	cout << c << '\t' << d << '\n';
	cout << a - b << '\n';
}