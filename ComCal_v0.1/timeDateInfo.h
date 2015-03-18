//Hamzah will handle this whole part

#pragma once
#include <string>
#include <time.h>

#include "ErrorLog.h"

namespace timeDateInfo{

	//checks if the date is valid
	//Argument: string in format DDMMYY
	bool isDateValid(std::string);

	//used to check whether time is within 0000 - 2359
	bool isTimeValid(int);
	bool isDayValid(std::string);
	bool isClashing(std::string);
	bool isLeapYear(int);
	std::string getMonthStr(int);

	//3 overloaded functions setStructTm
	//Arguments: 1=year, 2=month
	struct tm* setStructTm(int, int);
	//Arguments: month
	struct tm* setStructTm(int);
	//Default time at the moment of using the application
	struct tm* setStructTm();

};

