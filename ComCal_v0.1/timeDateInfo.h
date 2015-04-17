//@author A0110783L
#pragma once

#include <vector>
#include <time.h>

// DD, MM, YY length constant int declarations:
const int LENGTH_MDAYINPUT = 2;
const int LENGTH_MONTHINPUT = 2;
const int LENGTH_YEARINPUT = 2;

// Length of time input constant int declarations:
const int LENGTH_TIMEINPUT = 4;
const int LENGTH_HOURINPUT = 2;
const int LENGTH_MININPUT = 2;
const int LENGTH_MINDATEINPUT = 8;

// Leading 0 for date/time formatting constant string declaration:
const std::string leadingZero = "0";

// DD/MM/YY date input seperator constant string and index int declarations:
const int SIZE_SEPARATORSARRAY = 1;
const char SEPARATORS[SIZE_SEPARATORSARRAY] = { '/' };

const static std::string DAYSINPUT[14] = { "sunday", "sun", "monday", "mon", "tuesday", "tues", "wednesday", "wed", "thursday", "thurs", "friday", "fri", "saturday", "sat" };

namespace timeDateInfo {

	//checks if the mday, month and year number is valid
	//Argument: string in format of "DD", "MM", "YYYY"
	bool isMdayValid(std::string, int, int);	//Assumes month and year string inputs are valid.
	bool isMonthValid(std::string);
	bool isYearValid(std::string);

	//used to check whether time is within 0000 - 2359
	bool isTimeValid(std::string);
	bool isDayValid(std::string, int&);
	bool isLeapYear(int);
	bool isStringANum(std::string);

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

	//4 overloaded functions setStructTm
	//Arguments: 1=year, 2=month, 3=day
	struct tm* setStructTm(int year, int month, int day);
	//Arguments: 1=year, 2=month
	struct tm* setStructTm(int year, int month);
	//Arguments: month
	struct tm* setStructTm(int month);
	//Default time at the moment of using the application
	struct tm* setStructTm();

	struct tm* setDayStructTm(int);
};
