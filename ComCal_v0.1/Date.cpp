// Date.cpp
// Implementation of functions in the Date class
//@author A0119754X

#include "Date.h"

Date::Date(int day, int month, int year, int time) {
	_day = day;
	_month = month;
	_year = year;
	_time = time;
}

Date::Date() {
	_time = NULL;
}

Date::~Date() {
}

std::string Date::toString() {
	std::string dateString = "";

	dateString += typeConversions::intToString(_day) + "/" + typeConversions::intToString(_month) + "/" + typeConversions::intToString(_year%100) + " ";
	
	if (_time < 10) {
		dateString += "000" + typeConversions::intToString(_time);
	}
	else if (_time < 100) {
		dateString += "00" + typeConversions::intToString(_time);
	}
	else if (_time < 1000) {
		dateString += "0" + typeConversions::intToString(_time);
	}
	else {
		dateString += typeConversions::intToString(_time);
	}

	return dateString;
}

std::string Date::toGUIString(){
	return (typeConversions::intToString(_day) + "/" + typeConversions::intToString(_month) + "/" + typeConversions::intToString(_year));
}

int Date::getDay() {
	return _day;
}

int Date::getMonth() {
	return _month;
}

int Date::getYear() {
	return _year;
}

int Date::getTime() {
	return _time;
}

time_t Date::getTimeT() {
	struct tm* dateTimeInfo = timeDateInfo::setStructTm();
	dateTimeInfo->tm_mday=_day;
	dateTimeInfo->tm_mon = _month-1;
	dateTimeInfo->tm_year = _year;

	return mktime(dateTimeInfo);
}

bool Date::operator==(const Date &date) {
	if (_day != date._day)
		return false;
	if (_month != date._month)
		return false;
	if (_year != date._year)
		return false;
	return true;
}

bool Date::setDate(std::string date) {
	// Possible inputs for dates:
	// 1. DD/MM/YYYY
	//    - check by .find("/") twice
	// 2. "yesterday", "today", "tomorrow", "Monday", "Wednesday", "week" etc.
	//    - 1 and 2 have no spaces
	// 3. "next Wednesday", "last Friday", etc.
	//    - indicated by spaces
	// 4. "DD/MM/YYYY week", "next week", "last week", etc.
	//    - indicated by spaces
	// Input for time:
	// 1. Strictly HHMM in 24 hour format

	int space1 = date.find(" ");
	if (space1 == std::string::npos) { // No spaces. Either 1 or 2
		int slash1 = date.find("/");
		if (slash1 == std::string::npos) { // Input format number 2
			struct tm* currentTime = timeDateInfo::setStructTm();
			date = typeConversions::toLowerCase(date);
			if (date.compare(DATE_TODAY) == 0) {
				_day = currentTime->tm_mday;
				_month = currentTime->tm_mon + 1;
				_year = currentTime->tm_year;
			}
			else if (date.compare(DATE_YESTERDAY) == 0) {
				_day = currentTime->tm_mday - 1;
				if (_day == 0) {
					_month = currentTime->tm_mon;
					if (_month == 0) {
						_month = 12;
						_year=currentTime->tm_year-1;
					}
					else {
						_year = currentTime->tm_year;
					}
					_day = timeDateInfo::getDaysInMonth(_month, _year);
				}
				else {
					_month = currentTime->tm_mon + 1;
					_year = currentTime->tm_year;
				}
			}
			else if (date.compare(DATE_TOMORROW) == 0) {
				_day = currentTime->tm_mday + 1;
				if (_day > timeDateInfo::getDaysInMonth(currentTime->tm_mon, currentTime->tm_year)) {
					_month = currentTime->tm_mon + 2;
					if (_month > 12) {
						_month = 1;
						_year = currentTime->tm_year + 1;
					}
					else {
						_year = currentTime->tm_year;
					}
					_day = _day - timeDateInfo::getDaysInMonth(_month - 1, _year);
				}
				else {
					_month = currentTime->tm_mon + 1;
					_year = currentTime->tm_year;
				}
			}
			else if (date.compare(DATE_WEEK) == 0) {
				//@author A0085731A
				//For week: "week" will return the start date and time of the week
				int daysDifference = currentTime->tm_wday - 0;
				_day = currentTime->tm_mday - daysDifference;
				if (_day < 1) {
					_month = currentTime->tm_mon-1;
					if (_month == 0) {
						_month = 12;
						_year = currentTime->tm_year-1;
					}
					else {
						_year = currentTime->tm_year;
					}

					int numDaysInMonth = timeDateInfo::getDaysInMonth(_month - 1, _year);
					_day = numDaysInMonth + _day;
				}
				else {
					_month = currentTime->tm_mon + 1;
					_year = currentTime->tm_year;
				}
				_time = 0000;
			}
			else {
				//@author A0085731A
				//For day: e.g. "Monday", "Wednesday"
				int dayIndex;

				if (timeDateInfo::isDayValid(date, dayIndex)) {
					dayIndex = ((dayIndex + 2) / 2)-1;
					int daysDifference = dayIndex - currentTime->tm_wday;
					_day = currentTime->tm_mday + daysDifference;

					if (_day < 1) {
						_month = currentTime->tm_mon - 1;
						if (_month == 0) {
							_month = 12;
							_year = currentTime->tm_year - 1;
						}
						else {
							_year = currentTime->tm_year;
						}

						int numDaysInMonth = timeDateInfo::getDaysInMonth(_month - 1, _year);
						_day = numDaysInMonth + _day;
					}
					else {
						_month = currentTime->tm_mon + 1;
						_year = currentTime->tm_year;
					}
				}
				else {
					return false;
				}
			}
		}
		else { // Input format number 1
			int slash2 = date.find("/", slash1 + 1);
			if (slash2 == std::string::npos) {
				return false;
			}
			if (date.size() != 9) {
				return false;
			}
			if (timeDateInfo::isYearValid(date.substr(slash2 + 1))) {
				_year = typeConversions::stringToInt(date.substr(slash2 + 1))-1900;
				if (timeDateInfo::isMonthValid(date.substr(slash1 + 1, 2))) {
					_month = typeConversions::stringToInt(date.substr(slash1 + 1, 2));
					if (timeDateInfo::isMdayValid(date.substr(0, 2), date.substr(slash1 + 1, 2), date.substr(slash2 + 1))) {
						_day = typeConversions::stringToInt(date.substr(0, 2));
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	else {
		int space2 = date.find(" ", space1 + 1);
		if (space2 == std::string::npos) { // Either 3 or 4 with no time, or 1 or 2 with time
			std::string time = date.substr(space1 + 1);
			if (timeDateInfo::isTimeValid(time)) { // 1 or 2 with time
				if (!setDate(date.substr(0, space1))) {
					return false;
				}
				_time = typeConversions::stringToInt(time);
			}
			else { // Either 3 or 4 with no time
				//@author A0085731A
				if (!setDate(date.substr(space1 + 1))) {
					return false;
				}

				if (typeConversions::toLowerCase(date.substr(0, space1)) == DATE_LAST) {
					_day -= 7;
					if (_day < 1) {
						_month--;
						if (_month < 1) {
							_month = 12;
							_year--;
						}

						int numDaysInMonth = timeDateInfo::getDaysInMonth(_month - 1, _year);
						_day = numDaysInMonth + _day;
					}
				}
				else if (typeConversions::toLowerCase(date.substr(0, space1)) == DATE_NEXT) {
					_day += 7;

					int numDaysInMonth = timeDateInfo::getDaysInMonth(_month - 1, _year);

					if (_day > numDaysInMonth) {
						_month++;
						if (_month > 12) {
							_month = 1;
							_year++;
						}

						_day = _day - numDaysInMonth;
					}
				}
				else if (typeConversions::toLowerCase(date.substr(space1+1)) == DATE_WEEK&&date.substr(space1+1).find("/")!=std::string::npos) {
					//For week specified with date: "DD/MM/YYYY week" will return the start date and time of the week containing the specified date
					if (!setDate(date.substr(0, space1))) {
						return false;
					}

					struct tm* dateTime = timeDateInfo::setStructTm();
					dateTime->tm_mday = _day;
					dateTime->tm_mon = _month - 1;
					dateTime->tm_year = _year;
					time_t dateTimeT = mktime(dateTime);
					localtime(&dateTimeT);

					int daysDifference = dateTime->tm_wday - 0;
					_day = _day - daysDifference;
					if (_day < 1) {
						_month--;
						if (_month < 1) {
							_month = 12;
							_year--;
						}

						int numDaysInMonth = timeDateInfo::getDaysInMonth(_month - 1, _year);
						_day = numDaysInMonth + _day;
					}
					_time = 0000;
				}
				else {
					return false;
				}
			}
		}
		else { // 3 with time
			if (!setDate(date.substr(0, space2))) {
				return false;
			}
			std::string time = date.substr(space2 + 1);
			if (!timeDateInfo::isTimeValid(time)){
				return false;
			}
			_time = typeConversions::stringToInt(time);
		}
	}

	return true;
}

//@author A0085731A
bool Date::setTime(int time) {
	if (time < 0 || time > 2359) {
		return false;
	}
	else {
		return true;
	}
}

void Date::setEndOfWeek() {
	_day += 7;

	int numDaysInMonth = timeDateInfo::getDaysInMonth(_month - 1, _year);

	if (_day > numDaysInMonth) {
		_month++;
		if (_month > 12) {
			_month = 1;
			_year++;
		}

		_day = _day - numDaysInMonth;
	}
}

void Date::setEndOfDay() {
	_time = 2359;
}