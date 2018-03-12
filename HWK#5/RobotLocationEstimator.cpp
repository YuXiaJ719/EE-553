#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

void polar2Rect(double r, double theta, double &x,double &y){
	x = x + sin(theta*M_PI/180) * r;
	y = y + cos(theta*M_PI/180) * r;
}


int main(){
	ifstream f("hw3c.dat");

	vector<double> route; // Record the route of Robot
	double a, x = 0, y = 0; // x, y represent the location of robot
	int Length = 0; // Record number of steps robot forward

	while(!f.eof()){
		f >> a;
		route.push_back(a);
		Length++;

		if(a < 0)
			break;
		else{
			if(Length > 1 && Length % 2 == 0){
				cout << route[Length - 2] << ", " << route[Length - 1] << '\n';
				polar2Rect(route[Length - 1], route[Length - 2], x, y);
			}
		}
	}

	cout << "The robot's coordinate is: (" << x << "," << y << ")"<< '\n';
	return 0;
}