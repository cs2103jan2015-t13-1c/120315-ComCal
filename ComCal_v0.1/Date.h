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
	Date(); // For this constructor, use setDate() after creating object,
			// which returns boolean whether format is valid or invalid
	~Date();
	
	std::string toString();
	std::string toGUIString();

	// Getter methods
	int getDay();
	int getMonth();
	int getYear();
	int getTime();

	bool operator==(const Date &date); // Only makes sure same date; does not check time

	// Setter methods
	bool setDate(std::string date);
};