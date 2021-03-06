//@author A0119754X
// Date.cpp
// Implementation of functions in the Date class

#include "Date.h"

Date::Date(int day, int month, int year, int time) {
	if (year > 1900){
		year -= 1900;
	}

	_day = day;
	_month = month;
	_year = year;
	_time = time;
}

Date::Date() {
	_day = 0;
	_month = 0;
	_year = 0;
	_time = -1;
}

Date::~Date() {
}

// "DD/MM/YY HHRR"
std::string Date::toString() {
	return toGUIString() + toTimeString();
}

// "DD/MM/YY"
std::string Date::toGUIString(){
	std::string str = "";
	if (_day < 10) {
		str += "0";
	}
	str += typeConversions::intToString(_day) + "/";
	if (_month < 10) {
		str += "0";
	}
	str += typeConversions::intToString(_month) + "/" + typeConversions::intToString(_year + 1900);

	return str;
}

// " HHMM" if time exists and "" if it doesn't
std::string Date::toTimeString() {
	if (_time == -1) {
		return "";
	}
	std::string str = typeConversions::intToString(_time);
	while (str.size() < 4) {
		str = "0" + str;
	}
	return " " + str;
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

// Only makes sure same date; does not check time
bool Date::operator==(const Date &date) {
	if (_day != date._day) {
		return false;
	}
	if (_month != date._month) {
		return false;
	}
	if (_year != date._year) {
		return false;
	}
	return true;
}

bool Date::operator>(const Date &date) {
	if (_year > date._year) {
		return true;
	}
	if (_year < date._year) {
		return false;
	}
	if (_month > date._month) {
		return true;
	}
	if (_month < date._month) {
		return false;
	}
	if (_day > date._day) {
		return true;
	}
	if (_day < date._day) {
		return false;
	}
	if (_time > date._time) {
		return true;
	}
	return false;
}

//@author A0110783L
bool Date::operator<=(const Date &date) {

	if (date._year > _year) {
		return true;
	}
	else {
		if (date._month > _month && date._year == _year) {
			return true;
		}
		else {
			if (date._day >= _day && date._month == _month && date._year == _year) {
				return true;
			}
			else{
				return false;
			}
		}
	}
}

bool Date::operator>=(const Date &date) {
	if (date._year < _year) {
		return true;
	}
	else {
		if (date._month < _month && date._year == _year) {
			return true;
		}
		else {
			if (date._day <= _day && date._month == _month && date._year == _year) {
				return true;
			}
			else{
				return false;
			}
		}
	}
}

//@author A0085731A
bool Date::isDateDefined() {
	if (_day == 0) {
		return false;
	}
	if (_month == 0) {
		return false;
	}
	if (_year == 0) {
		return false;
	}
	return true;
}

//@author A0119754X
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
			date = typeConversions::toLowerCase(date);
			if (date.compare(DATE_TODAY) == 0) {
				struct tm* currentTime = timeDateInfo::setStructTm();
				_day = currentTime->tm_mday;
				_month = currentTime->tm_mon + 1;
				_year = currentTime->tm_year;
			}
			else if (date.compare(DATE_YESTERDAY) == 0) {
				struct tm* currentTime = timeDateInfo::setStructTm();
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
				struct tm* currentTime = timeDateInfo::setStructTm();
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
				//For week: "week" will return the start date and time of the week
				struct tm* currentTime = timeDateInfo::setStructTm();
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
				//For day: e.g. "Monday", "Wednesday"
				int dayIndex;

				if (timeDateInfo::isDayValid(date, dayIndex)) {
					struct tm* currentTime = timeDateInfo::setStructTm();
					dayIndex = ((dayIndex + 2) / 2) - 1;
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
					// Check if current date is uninitialized. If it is, return false.
					if (!isDateDefined()) {
						return false;
					}
					// Else, it has been set a date already, so set the time
					if (!typeConversions::isNumber(date)) {
						return false;
					}
					_time = typeConversions::stringToInt(date);
					return true;
				}
			}
		}
		else { // Input format number 1
			int slash2 = date.find("/", slash1 + 1);
			if (slash2 == std::string::npos) {
				return false;
			}

			std::string tempString = date.substr(slash2 + 1); // YYYY
			if (!timeDateInfo::isYearValid(tempString)) {
				return false;
			}
			_year = typeConversions::stringToInt(tempString) - 1900;

			tempString = date.substr(slash1 + 1, slash2 - slash1 - 1); // MM
			if (!timeDateInfo::isMonthValid(tempString)) {
				return false;
			}
			_month = typeConversions::stringToInt(tempString);

			tempString = date.substr(0, slash1); // DD
			if (!timeDateInfo::isMdayValid(tempString, _month, _year + 1900)) {
				return false;
			}
			_day = typeConversions::stringToInt(tempString);
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
				if (!timeDateInfo::isTimeValid(time)) {
					return false;
				}
				_time = typeConversions::stringToInt(time);
			}
			else { // Either 3 or 4 with no time
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
				else if (typeConversions::toLowerCase(date.substr(space1+1)) == DATE_WEEK) {
					int lol = date.substr(space1+1).find("/");
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

// If the date string has no date, then set it to be the same as the date in start date
bool Date::setDate(std::string date, Date* startDate) {
	if (startDate != NULL) {
		_day = startDate->_day;
		_month = startDate->_month;
		_year = startDate->_year;
	}
	if (!setDate(date)) {
		return false;
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