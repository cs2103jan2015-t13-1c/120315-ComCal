#include "timeDateInfo.h"
#include "keywords.h"
#include "ErrorLog.h"
#include "typeConversions.h"

//To do some logging just type your code then if there is an error just type ErrorLog::inputErrorLog(errorMessage)
//key in all error messages inside keywords.h as const std::strings

//@author A0085731A
; bool timeDateInfo::isDateValid(std::string dateInput) {
	if (dateInput.size() != 6) {
		return false;
	}

	int month = typeConversions::stringToInt(dateInput.substr(2, 2));
	int year = typeConversions::stringToInt(dateInput.substr(4, 2));

	if ((month < 1 || month>12) || (year < 0 || year > 99)) {
		return false;
	}

	int numDaysInMonth = timeDateInfo::getDaysInMonth(month - 1, year + 100);

	if (typeConversions::stringToInt(dateInput.substr(0, 2)) > numDaysInMonth) {
		return false;
	}

	return true;
}

//@author A0085731A
bool timeDateInfo::isTimeValid(int timeInput) {
	if (timeInput < 0 || timeInput > 2359) {
		return false;
	}

	return true;
}

//@author A0085731A
bool timeDateInfo::isDayValid(std::string dayInput, int& index) {
	bool isFound = false;

	const static std::string DAYSINPUT[14] = { "sunday", "sun", "monday", "mon", "tuesday", "tues", "wednesday", "wed", "thursday", "thurs", "friday", "fri", "saturday", "sat" };

	for (int i = 0; i < 14; i++) {
		if (dayInput == DAYSINPUT[i]) {
			index = i;
			isFound = true;
		}
	}

	return true;
}

bool timeDateInfo::isClashing(std::string) {
	return true;
}

bool timeDateInfo::isLeapYear(int year)
{
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

std::string timeDateInfo::getDayStr(int iter) {
	const static std::string DAYS[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	return DAYS[iter];
}

std::string timeDateInfo::getLowerDayStr(int iter) {
	const static std::string DAYS[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

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

	if ((iter == 1) && timeDateInfo::isLeapYear(year + 1900)) {
		daysInMonth[1] = 29;
	}

	return daysInMonth[iter];
}

struct tm* timeDateInfo::setStructTm(int year, int month) {
	struct tm* timeinfo = setStructTm(month);
	timeinfo->tm_year = year - 1900;
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