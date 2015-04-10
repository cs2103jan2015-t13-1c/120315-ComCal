// Date.h
// Contains the class that stores information about dates and times used in Task
//@author A0119754X

#pragma once

#include "Exceptions.h"
#include "ErrorLog.h"
#include "typeConversions.h"
#include "keywords.h"
#include "timeDateInfo.h"

#include <string>

class Date {
private:
	int _day;	// Day of month
	int _month;	// Month of year, i.e. 1: Jan, 2: Feb,...
	int _year;	// Number of years since 1900
	int _time;	// In hhmm 24h time notation
public:
	Date(int day, int month, int year, int time);
	Date(); // For this constructor, use setDate() after creating object,
			// which returns boolean whether format is valid or invalid
	~Date();
	
	std::string toString();
	std::string toGUIString();
	std::string toTimeString();

	// Getter methods
	int getDay();
	int getMonth();
	int getYear();
	int getTime();
	time_t getTimeT();

	bool operator==(const Date &date); // Only makes sure same date; does not check time
	bool operator>(const Date &date);
	bool isDateDefined();

	// Setter methods
	bool setDate(std::string date);
	bool setDate(std::string date, Date* startDate);
	bool setTime(int);
	void setEndOfWeek();
	void setEndOfDay();
};