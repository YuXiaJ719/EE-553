#include <iostream>
#include <string>
using namespace std;


int main() {
	string st("15:17:29");
	string::size_type sz;
	double f = stod(st, &sz);
	st = st.substr(sz + 1);
	double s = stod(st, &sz);
	st = st.substr(sz + 1);
	double t = stod(st, &sz);
	// cout << s;
}