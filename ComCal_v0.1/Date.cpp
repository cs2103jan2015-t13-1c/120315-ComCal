// Date.cpp
// Implementation of functions in the Date class
//@author A0119754X

#include "Date.h"
#include "typeConversions.h"
#include "keywords.h"
#include "timeDateInfo.h"

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

	dateString += typeConversions::intToString(_day) + "/" + typeConversions::intToString(_month) + "/" + typeConversions::intToString(_year) + " ";
	
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
	// 1. DD/MM/YY
	//    - check by .find("/") twice
	// 2. "yesterday", "today", "tomorrow", "Monday", "Wednesday", etc.
	//    - 1 and 2 have no spaces
	// 3. "next Wednesday", "last Friday", etc.
	//    - indicated by spaces
	// Input for time:
	// 1. Strictly HHMM in 24 hour format

	int space1 = date.find(" ");
	if (space1 == std::string::npos) { // No spaces. Either 1 or 2
		int slash1 = date.find("/");
		if (slash1 == std::string::npos) { // Input format number 2
			struct tm* currentTime = timeDateInfo::setStructTm();
			if (date.compare(DATE_TODAY) == 0) {
				_day = currentTime->tm_mday;
				_month = currentTime->tm_mon + 1;
				_year = currentTime->tm_year % 100;
			}
			else if (date.compare(DATE_YESTERDAY) == 0) {
				_day = currentTime->tm_mday - 1;
				if (_day == 0) {
					_month = currentTime->tm_mon;
					if (_month == 0) {
						_month = 12;
						_year = currentTime->tm_year % 100 - 1;
						if (_year == 0) {
							_year = 99;
						}
					}
					else {
						_year = currentTime->tm_year % 100;
					}
					_day = timeDateInfo::getDaysInMonth(_month, _year + 100);
				}
				else {
					_month = currentTime->tm_mon + 1;
					_year = currentTime->tm_year % 100;
				}
			}
			else if (date.compare(DATE_TOMORROW) == 0) {
				_day = currentTime->tm_mday + 1;
				if (_day > timeDateInfo::getDaysInMonth(currentTime->tm_mon, currentTime->tm_year)) {
					_month = currentTime->tm_mon + 2;
					if (_month > 12) {
						_month = 1;
						_year = (currentTime->tm_year + 1) % 100;
					}
					else {
						_year = currentTime->tm_year % 100;
					}
				}
				else {
					_month = currentTime->tm_mon + 1;
					_year = currentTime->tm_year % 100;
				}
			}
			else {
				//@author A0085731A
				int dayIndex;
				date = typeConversions::toLowerCase(date);

				if (timeDateInfo::isDayValid(date, dayIndex)) {
					dayIndex = ((dayIndex + 2) / 2)-1;
					int daysDifference = dayIndex - currentTime->tm_wday;
					time_t desiredDayOfWeekTimeT = mktime(currentTime) + (daysDifference*SECONDS_IN_DAY);

					if (daysDifference < 0) {
						desiredDayOfWeekTimeT += SECONDS_IN_WEEK;
					}

					struct tm* desiredDate = localtime(&desiredDayOfWeekTimeT);

					_day = desiredDate->tm_mday;
					_month = desiredDate->tm_mon + 1;
					_year = desiredDate->tm_year % 100;
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
			_day = typeConversions::stringToInt(date.substr(0, slash1));
			_month = typeConversions::stringToInt(date.substr(slash1 + 1, slash2 - slash1 - 1));
			_year = typeConversions::stringToInt(date.substr(slash2 + 1, date.length() - slash2 - 1));
		}
	}
	else {
		int space2 = date.find(" ", space1 + 1);
		if (space2 == std::string::npos) { // Either 3 with no time, or 1 or 2 with time
			std::string time = date.substr(space1 + 1, date.length() - space1);
			if (typeConversions::isNumber(time)) { // 1 or 2 with time
				if (!setDate(date.substr(0, space1))) {
					return false;
				}
				_time = typeConversions::stringToInt(time);
			}
			else { // 3 with no time
				//@author A0085731A
				if (!setDate(date.substr(space1 + 1))) {
					return false;
				}

				if (typeConversions::toLowerCase(date.substr(0, space1)) == DATE_LAST) {
					_day -= 7;
					if (_day < 1) {
						_month -= 1;
						if (_month < 1) {
							_month = 12;
							_year -= 1;
							if (_year < 0) {
								_year = 99;
							}
						}

						int numDaysInMonth = timeDateInfo::getDaysInMonth(_month - 1, _year + 100);
						_day = numDaysInMonth + (_day - 7);
					}
				}
				else if (typeConversions::toLowerCase(date.substr(0, space1)) == DATE_NEXT) {
					_day += 7;

					int numDaysInMonth = timeDateInfo::getDaysInMonth(_month - 1, _year + 100);

					if (_day > numDaysInMonth) {
						_month += 1;
						if (_month > 12) {
							_month = 1;
							_year += 1;
							if (_year > 99) {
								_year = 0;
							}
						}

						_day = _day - numDaysInMonth;
					}
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
			std::string time = date.substr(space2 + 1, date.length() - space2);
			if (!typeConversions::isNumber(time)) {
				return false;
			}
			if (!timeDateInfo::isTimeValid(typeConversions::stringToInt(time))){
				return false;
			}
			_time = typeConversions::stringToInt(time);
		}
	}

	return true;
}

//@author A0085731A
bool Date::setTime(int time) {
	if (timeDateInfo::isTimeValid(time)) {
		_time = time;
		return true;
	} else {
		return false;
	}
}