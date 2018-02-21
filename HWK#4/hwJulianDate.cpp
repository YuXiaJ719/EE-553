/*
	Author: Yu Xia
	Date: 02/21/2018
*/

#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

class baseTime{
private:
	struct tm t;
	time_t mt;

public:
	baseTime(){
		time_t raw_time;
		time(&raw_time);

		t = *localtime(&raw_time);
		mt = mktime(&t);
	}
	baseTime(int year, int mon=1, int day=1, int hour=0, int min=0, int sec=0){
		time_t raw_time;
		time(&raw_time);

		t = *localtime(&raw_time);

		t.tm_year = year - 1900;
		t.tm_mon = mon - 1;
		t.tm_mday = day;
		t.tm_hour = hour;
		t.tm_min = min;
		t.tm_sec = sec;

		mt = mktime(&t);
	}
	struct tm getT() const{
		return t;
	}
	time_t getMT() const{
		return mt;
	}
};

class JulianDate : public baseTime{
private:
	static int EPOCH;
	baseTime EPOCH_BT;
	int year, mon, day, hour, min, sec;
	double jdays;

public:
	JulianDate(int year, int mon, int day, int hour, int min, int sec): 
	baseTime(year, mon, day, hour, min, sec), EPOCH_BT(baseTime(getEPOCH())){
		time_t mt = getMT();
		jdays = difftime(mt, getEPOCH_BT().getMT()) / (24 * 60 * 60);
	}

	JulianDate():baseTime(), EPOCH_BT(baseTime(getEPOCH())){
		struct tm tt = getT();

		year = tt.tm_year + 1900;
		mon = tt.tm_mon + 1;
		day = tt.tm_mday;
		hour = tt.tm_hour ;
		min = tt.tm_min;
		sec = tt.tm_sec;

		time_t mt = getMT();
		jdays = difftime(mt, getEPOCH_BT().getMT()) / (24.0 * 60 * 60);
	}

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
	int getEPOCH() const{
		return EPOCH;
	}
	baseTime getEPOCH_BT() const{
		return EPOCH_BT;
	}
	double getJDAYS() const{
		return jdays;
	}

	double operator -(JulianDate d)const{
		return abs(getJDAYS() - d.getJDAYS());
	}

	JulianDate operator +(int gap)const{
		time_t origin = getMT();
		time_t newt = time(&origin) + gap * 86400;
		struct tm * newtm = localtime(&newt);

		return JulianDate(newtm->tm_year + 1900, newtm->tm_mon + 1, newtm->tm_mday, 
						  newtm->tm_hour, newtm->tm_min, newtm->tm_sec);
	}

	friend ostream& operator <<(ostream &s, JulianDate d){
		char str[50];
		struct tm temp =  d.getT();
		strftime(str, 50, "%F %X", &temp);
		s << str;
	return s;

	}
};

int JulianDate::EPOCH = 2010;

int main(){
	JulianDate newyear(2018, 1, 1, 0, 0, 0);
	JulianDate valentine(2018, 2, 14, 12, 0, 0);
	const JulianDate today;

	double days = valentine - newyear;
	JulianDate due = today + 7;

	cout << "Newyear: " << newyear << '\n';
	cout << "Valentine: " << valentine << '\n';
	cout << "The number of days between newyear and valentine: " << days << '\n';

	cout << "Today: " << today << '\n';
	cout << "Due day of today's HomeWork: " << due << '\n';
	

	cout << "\nyear: " << newyear.getYear()
			 << "\nmonth: " << newyear.getMonth()
			 << "\nday: " << newyear.getDay()
			 << "\nhour: " << newyear.getHour()
			 << "\nmin: " << newyear.getMin()
			 << "\nsec: " << newyear.getSec() << '\n';

	return 0;
}