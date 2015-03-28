// Show.cpp
// Implementation of functions in the Show class
//@author A0119754X

#include "Show.h"
#include "TextStorage.h"
#include "ComCalManager.h"
#include "timeDateInfo.h"
#include "keywords.h"

#include <ctype.h>

//int getMonthInput(std::string argument);
//int numOfWS(std::string argument);

std::string Show::execute(std::string argument) {
	std::string feedBack;
	int numOfWhiteSpace = numOfWS(argument);

	if (numOfWhiteSpace == 0) {
		
		//1st case: user specifies "show 'month'" without specifying the year
		if (getMonthInput(argument) != -1) {
			ComCalManager::getInstance()->setMonthDetails(timeDateInfo::setStructTm(getMonthInput(argument)));

			feedBack = timeDateInfo::getMonthStr(getMonthInput(argument)) + " shown";

			return  feedBack;
		}
		else {
			feedBack = INVALID_MONTH_INPUT;

			return feedBack;
		}

	}
	else{
		if (numOfWhiteSpace == 1) {

		}
	}

	feedBack = INVALID_SHOW_INPUT;
	return feedBack;
}

int Show::getMonthInput(std::string argument) {
	int monthIndex = -1;

	for (int i = 0; i < MONTHS_IN_YEAR; i++) {

		if (argument == timeDateInfo::getMonthStr(i)) {
			monthIndex = i;
		}

		if (argument == timeDateInfo::getLowerMonthStr(i)) {
			monthIndex = i;
		}

		if (argument == timeDateInfo::getShortMonthStr(i)) {
			monthIndex = i;
		}

		if (argument == timeDateInfo::getShortLowerMonthStr(i)) {
			monthIndex = i;
		}
	}

	return monthIndex;
}

int Show::numOfWS(std::string argument) {
	int numOfWhiteSpace = 0;

	for (int i = 0; i < argument.size(); i++) {
		if (isspace(argument[i])){
			numOfWhiteSpace++;
		}
	}

	return numOfWhiteSpace;
}

