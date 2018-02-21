#include <time.h>
#include <iostream>
using namespace std;

class JulianDate {
private:
	static int EPOCH;
// Make a "struct tm" to help to calculate difference between dates
	struct tm * t;
	time_t raw_time;
// base parameters of juliandate
	int year, mon, day, hour, min, sec;
// This the difference between Epoch and the Juliandate(in seconds)
	double jday;

public:
// Constructors
	JulianDate(int year, int mon, int day, int hour, int min, int second) : year(year), mon(mon), 
	day(day), hour(hour), min(min), sec(second){
		
		time(&raw_time);
		t = gmtime(&raw_time);
		set_tm();
	}
	
	JulianDate(){
		time(&raw_time);
		t = localtime(&raw_time);
		set_base();
	}

	void set_tm(){
		struct tm * tt = this->getT();
		tt->tm_year = this->getYear() - 1900;
		tt->tm_mon = this->getMonth() - 1;
		tt->tm_mday = this->getDay();
		tt->tm_hour = this->getHour();
		tt->tm_min = this->getMin();
		tt->tm_sec = this->getSec();
	}

	void set_base(){
		year = t->tm_year + 1900;
		mon = t->tm_mon + 1;
		day = t->tm_mday;
		hour = t->tm_hour;
		min = t->tm_min;
		sec = t->tm_sec;		
	}

	friend ostream& operator <<(ostream &s, JulianDate d){
		s << d.getMonth() << "/" << d.getDay() << "/" << d.getYear() << " " << d.getHour() << ":" 
		  << d.getMin() << ":" << d.getSec() << '\n';

		return s;
	}

	double operator -(JulianDate d) const{
		time_t t1 = mktime(t);
		time_t t2 = mktime(d.t);
		return difftime(t1, t2);
	}

	// JulianDate operator +(int d) const{

	// }

	int getYear() const{
		return year;
	}
	int getMonth() const{
		return mon;
	}
	int getDay() const{
		return day;
	}
	int getHour() const{
		return hour;
	}
	int getMin() const{
		return min;
	}
	int getSec() const{
		return sec;
	}
	struct tm * getT() const{
		return this->t;
	}
};

int JulianDate::EPOCH = 2000; // Jan.1 2000, 00:00:00 = 0

int main() {
	JulianDate newyear(2018, 1, 1, 0, 0, 0);
	JulianDate valentine(2018, 2, 14, 12, 0, 0);
	const JulianDate today; // get it from the system time: time(nullptr)
	                  // localtime
	double days = valentine - newyear;
	JulianDate due = today + 7;
	cout << today << '\n';

	cout << "\nyear: " << newyear.getYear()
			 << "\nmonth: " << newyear.getMonth()
			 << "\nday: " << newyear.getDay()
			 << "\nhour: " << newyear.getHour()
			 << "\nmin: " << newyear.getMin()
			 << "\nsec: " << newyear.getSec() << '\n';
}


		
