#include "timeDateInfo.h"
#include "keywords.h"
#include "ErrorLog.h"

//To do some logging just type your code then if there is an error just type ErrorLog::inputErrorLog(errorMessage)
//key in all error messages inside keywords.h as const std::strings

//prasoon
; bool timeDateInfo::isDateValid(std::string) {
	return true;
}

//weiliang
bool timeDateInfo::isTimeValid(int) {
	return 1;
}

//huangqin
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

//Hamzah
//returns the month in string form
//Argument: an int corresponding to the month, eg. 0=January, 1=February,..,11=December
std::string timeDateInfo::getMonthStr(int iter){
	const static std::string MONTHS[MONTHS_IN_YEAR] = { "January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October", "November", "December" };

	try{
		if (iter >= 0 && iter < 12){
			return MONTHS[iter];
		}
		else{
			throw GET_MONTH_STR_ERROR;
		}
	}
	catch(const std::string message){
		ErrorLog::inputErrorLog(message);
	}

	return NULL;
}

int timeDateInfo::getDaysInMonth(int iter, int year){
	int daysInMonth[MONTHS_IN_YEAR] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((iter == 1) && timeDateInfo::isLeapYear(year + 1900)){
		daysInMonth[1] = 29;
	}

	return daysInMonth[iter];
}

struct tm* timeDateInfo::setStructTm(int year, int month){
	time_t * rawtime = new time_t();
	struct tm * timeinfo = new struct tm();

	time(rawtime);
	timeinfo = localtime(rawtime);
	timeinfo->tm_mon = month;
	timeinfo->tm_year = year - 1900;

	return timeinfo;
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