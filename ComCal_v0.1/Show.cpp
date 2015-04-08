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
#include <algorithm>

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

	//TODO: trim the argument of any white spaces

	argument = typeConversions::toLowerCase(argument);

	int numOfWhiteSpace = 0;
	for (int k = 0; k < argument.size(); k++) {
		if (isspace(argument[k])) {
			numOfWhiteSpace++;
		}
	}

	if (numOfWhiteSpace >= 3) {
		return INVALID_SHOW_INPUT;
	}

	if (numOfWhiteSpace == 2) {
		std::size_t firstSpace = argument.find_first_of(" ", 0);
		std::size_t secSpace = argument.find_last_of(" ", 0);
		std::string firstArg = argument.substr(0, firstSpace);
		std::string secArg = argument.substr(firstSpace + 1, secSpace);
		std::string thiArg = argument.substr(secSpace + 1, argument.size());

		//TODO: More show stuff
		return INVALID_SHOW_INPUT;
	}
	else {
		if (numOfWhiteSpace == 1) {

			std::size_t space = argument.find_first_of(" ", 0);
			std::string firstArg = argument.substr(0, space);
			std::string secArg = argument.substr(space + 1, argument.size());

			//1) Method to display month with specified year eg. May 2016
			for (int i = 0; i < MONTHS_IN_YEAR; i++) {

				//condition to check if user specified a month with a year
				if (secArg == timeDateInfo::getLowerMonthStr(i) || firstArg == timeDateInfo::getLowerMonthStr(i)) {

					if (timeDateInfo::isStringANum(firstArg)) {
						std::swap(firstArg, secArg);
					}

					if (timeDateInfo::isStringANum(secArg) && secArg.size() == 4) {
						int year = typeConversions::stringToInt(secArg);

						if (year < 1900){
							return "Please input a year above 1900";
						}
						else {
//							year %= 1000;
//							year %= 100;
							TextStorage::getInstance()->displayMonthTasks(year, i + 1);
							struct tm* date = timeDateInfo::setStructTm(year, i);
							ComCalManager::getInstance()->setTimeDetails(date);

							return firstArg + " " + secArg + " shown";
						}
					}
					else{
						return "Please input a valid year in the format YYYY eg. 2016";
					}


					break;
				}
			} //end of month and year condition

			Date * tempDate = new Date();
			//method to display all the tasks in a week with specific date in the week
			if ((firstArg == WEEK) || (secArg == WEEK)) {

				if (secArg == WEEK) {
					std::swap(firstArg, secArg);
				}

				if (tempDate->setDate(secArg)) {
					TextStorage::getInstance()->displayWeekTasks(getDatesInWeek(tempDate));
					std::string sideBarTitle = tempDate->toGUIString() + " " + WEEK + " tasks\n";
					ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

					return (sideBarTitle + " shown\n");
				}
				else{
					return INVALID_DATE_INPUT;
				}

				delete tempDate;
				tempDate = nullptr;
			}

			//method to show todo tasks of the user specified date
			if ((firstArg == INPUT_TODO) || (secArg == INPUT_TODO)) {

				if (secArg == INPUT_TODO) {
					std::swap(firstArg, secArg);
				}

				if (tempDate->setDate(secArg)) {

				}
				else {
					return INVALID_DATE_INPUT;
				}
			}
		}
		else { //argument now has only one word, numOfWhiteSpace == 0

			if (argument == INPUT_TODO) { // Display all tasks that are not done
				ComCalManager::getInstance()->setSideBarTitle(ALL_TODO_TITLE);
				TextStorage::getInstance()->displayTodoTasks();
				return ALL_TODO_FEEDBACK;
			}

			if (argument == INPUT_DONE) { // Display all tasks that are done
				TextStorage::getInstance()->displayDoneTasks();
				ComCalManager::getInstance()->setSideBarTitle(ALL_DONE_TITLE);
				return ALL_DONE_FEEDBACK;
			}

			if (argument == DEADLINED_TASK) {
				TextStorage::getInstance()->displayDeadlinedTasks();
				ComCalManager::getInstance()->setSideBarTitle(ALL_TASKS_WITH_DEADLINE_TITLE);
				return ALL_DEADLINED_FEEDBACK;
			}

			// User specifies "show 'month'" 
			int month = getMonthInput(argument);
			if (month != -1) {
				struct tm* date = timeDateInfo::setStructTm(month);
//				int year = date->tm_year % 100;
				int year = date->tm_year + 1900;
				TextStorage::getInstance()->displayMonthTasks(year, month + 1);
				ComCalManager::getInstance()->setTimeDetails(date);

				return (timeDateInfo::getMonthStr(getMonthInput(argument)) + " shown");
			}

			if (argument == WEEK) {
				std::vector<Date*> weekDate = getDatesInWeek();

				TextStorage::getInstance()->displayWeekTasks(weekDate);
				ComCalManager::getInstance()->setSideBarTitle("This week's task");

				for (unsigned int j = 0; j < weekDate.size(); j++) {
					delete weekDate[j];
					weekDate[j] = nullptr;
				}

				return "Current week shown";
			}

			//user specifies a date through the formats, dd/mm/yy || tomorrow,today,yesterday
			Date* showDate = new Date();
			if (showDate->setDate(argument)) {
				TextStorage::getInstance()->displayDatedTasks(*showDate);
				std::string strDate = showDate->toGUIString();
				ComCalManager::getInstance()->setSideBarTitle(showDate->toString());

				return (strDate + " shown");
			}

			delete showDate;
			showDate = nullptr;
		} //end of one worded arguments
	}


	return INVALID_SHOW_INPUT;
}

int Show::getMonthInput(std::string argument) {
	for (int i = 0; i < MONTHS_IN_YEAR; i++) {

		if (argument == timeDateInfo::getLowerMonthStr(i)) {
			return i;
		}

		if (argument == timeDateInfo::getShortLowerMonthStr(i)) {
			return i;
		}
	}

	return -1;
}

std::vector<Date*> Show::getDatesInWeek() {
	std::vector<Date*> weekDate;

	struct tm * timeDetails = timeDateInfo::setStructTm();
	weekDate = getWeeklyDates(timeDetails);

	return weekDate;
}


std::vector<Date*> Show::getDatesInWeek(Date* specDate) {
	std::vector<Date*> weekDate;
	int year = specDate->getYear();
	int month = specDate->getMonth() - 1;
	int day = specDate->getDay();

	struct tm* timeDetails = timeDateInfo::setStructTm(year, month, day);
	weekDate = getWeeklyDates(timeDetails);

	return weekDate;
}

std::vector<Date*> Show::getWeeklyDates(struct tm* timeDetails) {
	std::vector<Date*> weekDate;
	int dayWeek = timeDetails->tm_wday;
	int dayMonth = timeDetails->tm_mday;
	int month = timeDetails->tm_mon;
	int year = timeDetails->tm_year;

	if (dayWeek != 0) {
		if (dayWeek >= dayMonth) {

			if (dayMonth == 0) {
				year--;
				month = 11;
			}
			else {
				month--;
			}

			dayWeek -= dayMonth;
			dayMonth = timeDateInfo::getDaysInMonth(month, year) - dayWeek;
		}
		else {
			dayMonth -= dayWeek;
		}
	}

	for (int i = 0; i < DAYS_IN_WEEK; i++) {
//		int shortYr = year % 100;
		int tempMonth = month + 1;
		weekDate.push_back(new Date(dayMonth, tempMonth, year, 0000));

		if (dayMonth == timeDateInfo::getDaysInMonth(month, year) && (month != 11)) {
			month++;
			dayMonth = 1;
		}
		else {
			if ((dayMonth == timeDateInfo::getDaysInMonth(month, year)) && (month == 11)){
				year++;
				month = 0;
				dayMonth = 1;
			}
			else {
				dayMonth++;
			}
		}
	}

	return weekDate;
}
