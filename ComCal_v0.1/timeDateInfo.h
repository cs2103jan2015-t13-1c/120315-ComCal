//Hamzah will handle this whole part

#pragma once

#include <string>
#include <time.h>

//DD, MM, YY length constant int declarations:
const int LENGTH_MDAYINPUT = 2;
const int LENGTH_MONTHINPUT = 2;
const int LENGTH_YEARINPUT = 2;

//Length of time input constant int declarations:
const int LENGTH_TIMEINPUT = 4;
const int LENGTH_HOURINPUT = 2;
const int LENGTH_MININPUT = 2;

//Leading 0 for date/time formatting constant string declaration:
const std::string leadingZero = "0";

//DD/MM/YY date input seperator constant string and index int declarations:
const int SIZE_SEPARATORSARRAY = 1;
const char SEPARATORS[SIZE_SEPARATORSARRAY] = { '/' };

namespace timeDateInfo {

	//checks if the date is valid
	//Argument: string in format DDMMYY
	bool isDateValid(std::string);

	//used to check whether time is within 0000 - 2359
	bool isTimeValid(int);
	bool isDayValid(std::string, int&);
	bool isClashing(std::string);
	bool isLeapYear(int);

	std::string getMonthStr(int);
	std::string getLowerMonthStr(int);
	std::string getShortMonthStr(int);
	std::string getShortLowerMonthStr(int);

	std::string getDayStr(int);
	std::string getLowerDayStr(int);
	std::string getShortDayStr(int);
	std::string getShortLowerDayStr(int);

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

	struct tm* setDayStructTm(int);
};

