//Hamzah will handle this whole part

#pragma once

#include <string>
#include <time.h>

namespace timeDateInfo {

	//checks if the date is valid
	//Argument: string in format DDMMYY
	bool isDateValid(std::string);

	//used to check whether time is within 0000 - 2359
	bool isTimeValid(int);
	bool isDayValid(std::string);
	bool isClashing(std::string);
	bool isLeapYear(int);
	std::string getMonthStr(int);

	//Arguments: 1) iter of the corresponding month, 0-Jan,..,11-Dec 2)year of the month
	//Returns: Number of days in the month
	int getDaysInMonth(int, int);

	//3 overloaded functions setStructTm
	//Arguments: 1=year, 2=month
	tm* setStructTm(int, int);
	//Arguments: month
	struct tm* setStructTm(int);
	//Default time at the moment of using the application
	struct tm* setStructTm();

};

