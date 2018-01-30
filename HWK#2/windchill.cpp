#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double cal_windchill(double t, double v){
	return 35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16);
}

int main(){
	cout << "Wind(vertical)";
	cout << setw(60) << "Temperature(F)(horizontal)\n";
	cout << "(mph)";
	for(int a = 40; a >= -45; a -= 5){
		if(a == 40)
			cout << setw(4) << a;
		else
			cout << setw(6) << a; 
	}
	cout << "\n";
	for(double j = 5.0; j <= 60.0; j += 5.0){
		cout << setw(3) << j;
		for(double i = 40.0; i >= -45.0; i += -5.0){
			cout << setw(6) << round(cal_windchill(i, j));
		}
		cout << endl;
	}
	return 0;
}