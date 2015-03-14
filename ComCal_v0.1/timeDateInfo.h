#pragma once
#include <string>
#include <time.h>

namespace timeDateInfo{

	bool isDateValid(std::string);
	bool isTimeValid(std::string);
	bool isDayValid(std::string);
	bool isClashing(std::string);
	bool isLeapYear(int);
	std::string getMonthStr(int);

	//Arguments: 1=year, 2=month
	struct tm* setStructTm(int, int);
	//Arguments: month
	struct tm* setStructTm(int);
	struct tm* setStructTm();

};

