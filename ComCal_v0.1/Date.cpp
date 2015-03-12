#include "Date.h"
#include "typeConversions.h"

Date::Date(int day, int month, int year, int time) {
	_day = day;
	_month = month;
	_year = year;
	_time = time;
}

// TODO Assuming date format is "DD/MM/YY" for now
Date::Date(std::string date, int time) {
	setDate(date);
	_time = time;
}

// TODO Assuming date format is "DD/MM/YY HHMM" for now
Date::Date(std::string date) {
	int space = date.find(" ");
	setDate(date.substr(0, space));
	_time = typeConversions::stringToInt(date.substr(space + 1, date.length() - space));
}

Date::~Date() {
}

std::string Date::toString() {
	return (typeConversions::intToString(_day) + "\n" + typeConversions::intToString(_month) + "\n" + typeConversions::intToString(_year) + "\n" + typeConversions::intToString(_time));
}

// TODO Assuming date format is "DD/MM/YY HHMM" for now
void Date::setDate(std::string ddmmyy) {
	int slash1 = ddmmyy.find("/");
	int slash2 = ddmmyy.find("/", slash1 + 1);
	_day = typeConversions::stringToInt(ddmmyy.substr(0, slash1));
	_month = typeConversions::stringToInt(ddmmyy.substr(slash1 + 1, slash2 - slash1 - 1));
	_year = typeConversions::stringToInt(ddmmyy.substr(slash2 + 1, ddmmyy.length() - slash2 - 1));
}