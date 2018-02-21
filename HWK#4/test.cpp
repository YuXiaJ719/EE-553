#include <iostream>
#include <time.h>
using namespace std;

int main(){
	time_t today;
	struct tm * ptm;
	time(&today);

	ptm = gmtime(&today);
	cout << ptm->tm_year << '\n';
	cout << ptm->tm_mon << '\n';
	cout << ptm->tm_mday << '\n';
	cout << ptm->tm_hour << '\n';
	cout << ptm->tm_min << '\n';
	cout << ptm->tm_sec << '\n';
}
