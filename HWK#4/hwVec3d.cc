/*
	Author: Yu Xia
	Date: 2/16/2018
*/

#include <iostream>
#include <cmath>
using namespace std;

class Vec3d{
private:
	double fn, sn, tn;
public:
	Vec3d(double a = 0, double b = 0, double c = 0) :fn(a), sn(b), tn(c) {}

	Vec3d operator +(Vec3d rightVec) const{
		return Vec3d(fn + rightVec.fn, sn + rightVec.sn, tn + rightVec.tn);
	}

	Vec3d operator -(Vec3d rightVec) const{
		return Vec3d(fn - rightVec.fn, sn - rightVec.sn, tn - rightVec.tn);
	}

	Vec3d operator -() const{
		return Vec3d(-fn, -sn, -tn);
	}

	friend ostream& operator <<(ostream& s, Vec3d rightVec){
		s << rightVec.fn << ',' << rightVec.sn << ',' << rightVec.tn;
		return s;
	}

	double dot(Vec3d rightVec) const{
		return fn * rightVec.fn + sn * rightVec.sn + tn * rightVec.tn; 
	}

	double mag() const{
		return sqrt(pow(fn, 2) + pow(sn, 2) + pow(tn, 2));
	}

	double magSq() const{
		return pow(fn, 2) + pow(sn, 2) + pow(tn, 2);
	}

	double dist(Vec3d rightVec) const{
		return sqrt(pow(fn - rightVec.fn, 2) + pow(sn - rightVec.sn, 2) + pow(tn - rightVec.tn, 2));
	}

	static double dot(Vec3d leftVec, Vec3d rightVec){
		return leftVec.fn * rightVec.fn +leftVec.sn * rightVec.sn + leftVec.tn * rightVec.tn;
	}	

	friend double dot(Vec3d leftVec, Vec3d rightVec){
		return leftVec.fn * rightVec.fn +leftVec.sn * rightVec.sn + leftVec.tn * rightVec.tn;
	}

};


int main() {
	// use friend operators
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d d(10.); // d is a function that returns Vec3d
	const Vec3d e;

	const Vec3d f = a + e;
	const Vec3d g = b - d; // d is not an object, pick a different one
	double x = dot(f, g); // regular function
	double y = Vec3d::dot(f,g); // static function
	double z = f.dot(g); // method
	const Vec3d h = -b;

	double dist = f.mag(); // square root of sum of square
	double dist2 = f.magSq(); // sum of square
	double dist3 = f.dist(g); // sqrt or sum of square of diff
	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';
	cout << e << '\n';
	cout << f << '\n';
	cout << g << '\n';
	cout << h << '\n';
	// cout << x << ' ' << y << ' ' << z << '\n';
	// cout << dist << ' ' << dist2 << ' ' << dist3 << '\n';
}

	

	
	
