#include "timeDateInfo.h"
#include "keywords.h"

bool timeDateInfo::isDateValid(std::string) {
	return true;
}

bool timeDateInfo::isTimeValid(std::string) {
	return true;
}

bool timeDateInfo::isDayValid(std::string) {
	return true;
}

bool timeDateInfo::isClashing(std::string) {
	return true;
}

bool timeDateInfo::isLeapYear(int year)
{
	bool isLeap = false;

	if (year % 4 != 0){
		isLeap = false;
	}
	else{
		if (year % 100 != 0){
			isLeap = true;
		}
		else{
			if (year % 400 != 0){
				isLeap = false;
			}
			else{
				isLeap = true;
			}
		}
	}

	return isLeap;
}

//returns the month in string form
//Argument: an int corresponding to the month, eg. 0=January, 1=February,..,11=December
std::string timeDateInfo::getMonthStr(int iter){
	const static std::string MONTHS[MONTHS_IN_YEAR] = { "January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October", "November", "December" };

	return MONTHS[iter];
}

struct tm* timeDateInfo::setStructTm(int month){
	time_t * rawtime = new time_t();
    struct tm * timeinfo = new struct tm();

	time(rawtime);
	timeinfo = localtime(rawtime);
	timeinfo->tm_mon = month;

	return timeinfo;
}

struct tm* timeDateInfo::setStructTm(){
	time_t * rawtime = new time_t();
	struct tm * timeinfo = new struct tm();

	time(rawtime);
	timeinfo = localtime(rawtime);

	return timeinfo;
}