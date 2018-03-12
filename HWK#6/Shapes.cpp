#include <iostream>
#include <cmath>
using namespace std;

class Shape{
public:
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
};

class Rect : public Shape{
private:
	double length, width;

public:
	Rect(double length, double width) : Shape(), length(length), width(width){}

	double area() const{
		return length * width;
	}

	double perimeter() const{
		return 2 * (length + width);
	}
};

class Circle : public Shape{
private:
	double r;

public:
	Circle(double r) : Shape(), r(r){}

	double area() const{
		return M_PI * r * r;
	}

	double perimeter() const{
		return 2 * M_PI * r;
	}
};


int main() {
  Rect r(5.0, 4.0);
  cout << r.area() << '\n';  // should print out 20
  cout << r.perimeter() << '\n'; // should print 18
  
  Circle c(2);
  cout << c.area() << '\n';  // should be pi*r2 about 12.4
  cout << c.perimeter() << '\n'; // should be 2*pi*r about 12.28
  
  Shape* s = &r;
  cout << s->area() << '\n'; // polymorphic call

  s = &c;
  cout << s->area() << '\n';// polymorphic call
}