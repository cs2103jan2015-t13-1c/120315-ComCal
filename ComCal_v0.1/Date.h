// Date.h
// Contains the class that stores information about dates and times used in Task
//@author A0119754X

#pragma once

#include <string>

class Date {
private:
	int _day;
	int _month;
	int _year;
	int _time; // In hhmm 24h time notation
public:
	Date(int day, int month, int year, int time);
	Date(std::string date, int time);
	Date(std::string);
	~Date();
	
	std::string toString();

	void setDate(std::string);

	int getDay();
	int getMonth();
	int getYear();
};