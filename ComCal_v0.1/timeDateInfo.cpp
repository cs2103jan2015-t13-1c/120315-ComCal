//@author A0110783L
#include "timeDateInfo.h"
#include <time.h>
#include "typeConversions.h"
#include "keywords.h"

//To do some logging just type your code then if there is an error just type ErrorLog::inputErrorLog(errorMessage)
//key in all error messages inside keywords.h as const std::strings
;
//@author A0085731A
bool timeDateInfo::isMdayValid(std::string mdayInput, int month, int year) {
	if (!typeConversions::isNumber(mdayInput)) {
		return false;
	}

	int numDaysInMonth = timeDateInfo::getDaysInMonth(month - 1, year - 1900);

	if (typeConversions::stringToInt(mdayInput) < 1 || typeConversions::stringToInt(mdayInput) > numDaysInMonth) {
		return false;
	}

	return true;
}

//@author A0110783L
bool timeDateInfo::isMonthValid(std::string monthInput) {
	if (!typeConversions::isNumber(monthInput)) {
		return false;
	}
	int month = typeConversions::stringToInt(monthInput);
	if (month <= 0) {
		return false;
	}
	if (month > 12) {
		return false;
	}
	return true;
}

bool timeDateInfo::isYearValid(std::string yearInput) {
	if (!typeConversions::isNumber(yearInput)) {
		return false;
	}

	if (typeConversions::stringToInt(yearInput) < 1900) {
		return false;
	}

	return true;
}

//@author A0119754X
bool timeDateInfo::isTimeValid(std::string timeInput) {
	if (timeInput.size() != 4) {
		return false;
	}
	if (!typeConversions::isNumber(timeInput)) {
		return false;
	}
	int hour = typeConversions::stringToInt(timeInput.substr(0, 2));
	if (hour < 0) {
		return false;
	}
	if (hour >= 24) {
		return false;
	}
	int minutes = typeConversions::stringToInt(timeInput.substr(2, 2));
	if (minutes < 0) {
		return false;
	}
	if (minutes >= 60) {
		return false;
	}
	return true;
}

//@author A0085731A
bool timeDateInfo::isDayValid(std::string dayInput, int& index) {
	bool isFound = false;

	for (int i = 0; i < 14; i++) {
		if (dayInput == DAYSINPUT[i]) {
			index = i;
			isFound = true;
		}
	}

	return isFound;
}

//@author A0110783L
bool timeDateInfo::isLeapYear(int year) {

	if (year < 1900) {
		year += 1900;
	}

	bool isLeap = false;

	if (year % 4 != 0) {
		isLeap = false;
	}
	else{
		if (year % 100 != 0) {
			isLeap = true;
		}
		else{
			if (year % 400 != 0) {
				isLeap = false;
			}
			else{
				isLeap = true;
			}
		}
	}

	return isLeap;
}


bool timeDateInfo::isStringANum(std::string str) {

	std::string::iterator iter = str.begin();
	while (iter != str.end() && isdigit(*iter)) {
		++iter;
	}

	return !str.empty() && iter == str.end();
}


std::string timeDateInfo::getDayStr(int iter) {
	const static std::string DAYS[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	return DAYS[iter];
}

std::string timeDateInfo::getLowerDayStr(int iter) {
	const static std::string DAYS[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

	return DAYS[iter];
}

std::string timeDateInfo::getShortDayStr(int iter) {
	const static std::string DAYS[] = { "Sun", "Mon", "Tue", "Wed", "Thurs", "Fri", "Sat" };

	return DAYS[iter];
}

std::string timeDateInfo::getShortLowerDayStr(int iter) {
	const static std::string DAYS[28] = { "sun", "mon", "tue", "wed", "thurs", "fri", "sat" };

	return DAYS[iter];
}

//Hamzah
//returns the month in string form
//Argument: an int corresponding to the month, eg. 0=January, 1=February,..,11=December
std::string timeDateInfo::getMonthStr(int iter) {
	const static std::string MONTHS[MONTHS_IN_YEAR] = { "January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October", "November", "December" };

	return MONTHS[iter];
}

std::string timeDateInfo::getLowerMonthStr(int iter) {
	const static std::string MONTHS[MONTHS_IN_YEAR] = { "january", "february", "march", "april", "may",
		"june", "july", "august", "september", "october", "november", "december" };

	return MONTHS[iter];
}


std::string timeDateInfo::getShortMonthStr(int iter) {
	const static std::string MONTHS[MONTHS_IN_YEAR] = { "Jan", "Feb", "Mar", "Apr", "May",
		"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return MONTHS[iter];
}

std::string timeDateInfo::getShortLowerMonthStr(int iter) {
	const static std::string MONTHS[MONTHS_IN_YEAR] = { "jan", "feb", "mar", "apr", "may",
		"jun", "jul", "aug", "sep", "oct", "nov", "dec" };

	return MONTHS[iter];
}

int timeDateInfo::getDaysInMonth(int iter, int year) {
	int daysInMonth[MONTHS_IN_YEAR] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((iter == 1) && timeDateInfo::isLeapYear(year)) {
		daysInMonth[1] = 29;
	}

	return daysInMonth[iter];
}

struct tm* timeDateInfo::setStructTm(int year, int month, int day) {
	struct tm* timeinfo = setStructTm(year, month);
	timeinfo->tm_mday = day;
	mktime(timeinfo);
	return timeinfo;
}

struct tm* timeDateInfo::setStructTm(int year, int month) {
	struct tm* timeinfo = setStructTm(month);
	if (year >= 1900) {
		timeinfo->tm_year = year - 1900;
	}
	else {
		timeinfo->tm_year = year;
	}

	return timeinfo;
}

struct tm* timeDateInfo::setStructTm(int month) {
	struct tm* timeinfo = setStructTm();
	timeinfo->tm_mon = month;

	return timeinfo;
}

struct tm* timeDateInfo::setStructTm() {
	time_t rawtime;
	time(&rawtime);
	struct tm* timeinfo = localtime(&rawtime);

	return timeinfo;
}

struct tm* timeDateInfo::setDayStructTm(int day) {
	struct tm* timeinfo = setStructTm();
	timeinfo->tm_wday = day;

	return timeinfo;
}