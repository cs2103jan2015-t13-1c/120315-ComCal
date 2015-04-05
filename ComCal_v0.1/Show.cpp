// Show.cpp
// Implementation of functions in the Show class
//@author A0119754X

#include "Show.h"
#include "TextStorage.h"
#include "ComCalManager.h"
#include "timeDateInfo.h"
#include "keywords.h"
#include "typeConversions.h"
#include "Date.h"

#include <ctype.h>

Show::Show() : Command() {
}

Show::~Show() {
}

std::string Show::execute(std::string argument) {
	std::string feedBack;

	if (argument.size() <= 0) { // Display all tasks
		TextStorage::getInstance()->displayAllTasks();
		return ALL_TASKS_FEEDBACK;
	}

	argument = typeConversions::toLowerCase(argument);

	if (argument == INPUT_TODO) { // Display all tasks that are not done
		TextStorage::getInstance()->displayToDoTasks();
		return ALL_TODO_FEEDBACK;
	}
	
	if (argument == INPUT_DONE) { // Display all tasks that are done
		TextStorage::getInstance()->displayDoneTasks();
		return ALL_DONE_FEEDBACK;
	}

	// User specifies "show 'month'" without specifying the year
	int month = getMonthInput(argument);
	if (month != -1) {
		TextStorage::getInstance()->displayMonthTasks(month + 1);
		struct tm* date = timeDateInfo::setStructTm(month);
		ComCalManager::getInstance()->setTimeDetails(date);
		return (timeDateInfo::getMonthStr(getMonthInput(argument)) + " shown");
	}

	Date* showDate = new Date();
	if (showDate->setDate(argument)) {
		TextStorage::getInstance()->displayDatedTasks(*showDate);
		std::string strDate = showDate->toGUIString();
		delete showDate;
		return (strDate + " shown");
	}
	
	delete showDate;
	return INVALID_SHOW_INPUT;
}

int Show::getMonthInput(std::string argument) {
	for (int i = 0; i < MONTHS_IN_YEAR; i++) {
		if (argument == timeDateInfo::getMonthStr(i)) {
			return i;
		}

		if (argument == timeDateInfo::getLowerMonthStr(i)) {
			return i;
		}

		if (argument == timeDateInfo::getShortMonthStr(i)) {
			return i;
		}

		if (argument == timeDateInfo::getShortLowerMonthStr(i)) {
			return i;
		}
	}

	return -1;
}

