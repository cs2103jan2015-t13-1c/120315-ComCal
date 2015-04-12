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
#include <time.h>

Show::Show() : Command() {
}

Show::~Show() {
}

std::string Show::execute(std::string argument) {
	std::string feedBack;
	std::string sideBarTitle;
	int count;
	int code = ALL_CODE;

	if (argument.size() <= 0) { // Default current month
		int year = timeDateInfo::setStructTm()->tm_year + 1900;
		int month = timeDateInfo::setStructTm()->tm_mon + 1;

		count = TextStorage::getInstance()->displayMonthTasks(ALL_CODE, year, month);
		ComCalManager::getInstance()->setSideBarTitle(timeDateInfo::getMonthStr(month - 1) + " " + typeConversions::intToString(year));
		return prepShowFeedback(CURRENT_MONTH_TASKS, count);
	}

	argument = typeConversions::toLowerCase(argument);

	int numOfWhiteSpace = Show::countWhiteSpace(argument);
	
	if (numOfWhiteSpace >= 3) {
		return INVALID_SHOW_INPUT;
	}

	if (numOfWhiteSpace == 2) {
		std::size_t firstSpace = argument.find_first_of(" ", 0);
		std::size_t secSpace = argument.find_first_of(" ", firstSpace+1);
		std::string firstArg = argument.substr(0, firstSpace);
		std::string secArg = argument.substr(firstSpace + 1, secSpace-firstSpace-1);
		std::string thiArg = argument.substr(secSpace + 1, argument.size());

		
		if (isTodoOrDone(firstArg, secArg, thiArg) && isArgYear(firstArg, secArg, thiArg) && isValidMonth(firstArg, secArg, thiArg)) {
			if (getMonthInput(secArg) != -1) {
				std::swap(firstArg, secArg);
			}
			else {
				if (getMonthInput(thiArg) != -1){
					std::swap(firstArg, thiArg);
				}
			}

			if (isTodoOrDone(secArg)) {
				std::swap(secArg, thiArg);
			}

			code = getCode(thiArg);
			int month = getMonthInput(firstArg);

			if (month == -1) {
				return INVALID_MONTH_INPUT;
			}

			return showMonthYear(code, month, firstArg, secArg);

		}//end show month year todo/done



		//TODO: More show stuff
		// Hamzah, help me ensure that the message that returns to feedback bar includes the number of tasks shown. Thanks!
		return INVALID_SHOW_INPUT;
	}
	else {
		if (numOfWhiteSpace == 1) {

			std::size_t space = argument.find_first_of(" ", 0);
			std::string firstArg = argument.substr(0, space);
			std::string secArg = argument.substr(space + 1, argument.size());

			//1) Method to display month with specified year eg. May 2016
				//condition to check if user specified a month with a year
			//2)method handles todo or done with months in the current year
				if (getMonthInput(firstArg) != -1 || getMonthInput(secArg) != -1) {

					if (firstArg == INPUT_TODO || secArg == INPUT_TODO || firstArg == INPUT_DONE || secArg == INPUT_DONE) {

						if (firstArg == INPUT_TODO || firstArg == INPUT_DONE) {
							std::swap(firstArg, secArg);
						}

						code = ALL_CODE; // initialised to ALL_CODE in case of errors in the next few lines

						code = getCode(secArg);

						int month = getMonthInput(firstArg);
						if (month == -1) {
							return INVALID_MONTH_INPUT;
						}

						struct tm* date = timeDateInfo::setStructTm(month);
						int year = date->tm_year + 1900;

						count = TextStorage::getInstance()->displayMonthTasks(code, year, month + 1);
						sideBarTitle = timeDateInfo::getMonthStr(month) + CAL_WHITE_SPACE + typeConversions::intToString(year) + CAL_WHITE_SPACE + secArg + " tasks\n";
						ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

						return prepShowFeedback(sideBarTitle, count);

					}//end of todo/done month (current year)
					else {//following method is for month year

						if (timeDateInfo::isStringANum(firstArg)) {
							std::swap(firstArg, secArg);
						}
						int month = getMonthInput(firstArg);

						if (month == -1) {
							return INVALID_MONTH_INPUT;
						}

						return showMonthYear(ALL_CODE, month, firstArg, secArg);
					}//end of month and year method

				}//end of month and year || month todo/done condition


			//1)Method to display all the tasks in a week with specific date in the week
			//2)Method to display todo/done tasks in the current week
			if (((firstArg == WEEK) || (secArg == WEEK))) {

				if (firstArg != DATE_NEXT && secArg != DATE_NEXT) {

					if (secArg == WEEK) {
						std::swap(firstArg, secArg);
					}

					Date tempDate;
					if (tempDate.setDate(secArg)) { //method for show week date
						count = TextStorage::getInstance()->displayWeekTasks(ALL_CODE, getDatesInWeek(tempDate));
						sideBarTitle = tempDate.toGUIString() + CAL_WHITE_SPACE + WEEK + TASKS;
						ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

						return prepShowFeedback(sideBarTitle, count);
					}
					else{ //method for show week todo/done
						if (secArg == INPUT_TODO || secArg == INPUT_DONE) {
							if (secArg == INPUT_TODO) {
								code = TODO_CODE;
								sideBarTitle = THIS_WEEK_TODO_TASK_TITLE;
								feedBack = THIS_WEEK_TODO_TASKS_FEEDBACK;
							}
							else {
								code = DONE_CODE;
								sideBarTitle = THIS_WEEK_DONE_TASK_TITLE;
								feedBack = THIS_WEEK_DONE_TASKS_FEEDBACK;
							}

							count = TextStorage::getInstance()->displayWeekTasks(code, getDatesInWeek());
							ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

							return prepShowFeedback(feedBack, count);
						}
						else{
							return INVALID_WEEK_INPUT;
						}
					}
				}

			}//end of all tasks within specific date in week

			//method to show todo tasks of the user specified date
			if ((firstArg == INPUT_TODO) || (secArg == INPUT_TODO)) {

				if (secArg == INPUT_TODO) {
					std::swap(firstArg, secArg);
				}

				Date * tempDate = new Date();
				if (tempDate->setDate(secArg)) {
					count = TextStorage::getInstance()->displayTodoTasks(*tempDate);
					sideBarTitle = tempDate->toGUIString() + DATED_DONE_TASKS;

				}
				else {
					return INVALID_DATE_INPUT;
				}

				delete tempDate;
			}//end of todo tasks within specified date

			//method to show done tasks of the user specified date
			if ((firstArg == INPUT_DONE) || (secArg == INPUT_DONE)) {

				if (secArg == INPUT_DONE) {
					std::swap(firstArg, secArg);
				}
				Date tempDate;
				if (tempDate.setDate(secArg)) {
					count = TextStorage::getInstance()->displayTodoTasks(tempDate);
					sideBarTitle = tempDate.toGUIString() + " " + INPUT_DONE + " tasks\n";
					ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

					return prepShowFeedback(sideBarTitle, count);
				}
				else {
					return INVALID_DATE_INPUT;
				}
			}//end of show done tasks within specified date

			//method to show todo/done floating tasks
			if (firstArg == FLOATING_TASKS || secArg == FLOATING_TASKS) {

				if (secArg == FLOATING_TASKS) {
					std::swap(firstArg, secArg);
				}

				bool isDone;
				if (secArg == INPUT_DONE) {
					isDone = true;
				}
				else {
					if (secArg == INPUT_TODO) {
						isDone = false;
					}
					else {
						return TODO_DONE_INPUT_ERROR;
					}
				}

				count = TextStorage::getInstance()->displayFloatingTasks(isDone);

				if (isDone){
					ComCalManager::getInstance()->setSideBarTitle(ALL_DONE_FLOATING_TASKS_TITLE);
				}
				else {
					ComCalManager::getInstance()->setSideBarTitle(ALL_TODO_FLOATING_TASKS_TITLE);
				}


				if (count == 0) {
					return ZERO_SHOW_RESULTS;
				}
				else {
					if (isDone){
						return prepShowFeedback(ALL_DONE_FLOATING_TASKS_FEEDBACK, count);
					}
					else {
						return prepShowFeedback(ALL_TODO_FLOATING_TASKS_FEEDBACK, count);
					}
				}

			}//end of todo/done floating tasks

			//method to show next week or next month todo&done tasks
			if ((firstArg == DATE_NEXT || secArg == DATE_NEXT)) {
				if (firstArg == DATE_MONTH || secArg == DATE_MONTH || secArg == DATE_WEEK || firstArg == DATE_WEEK) {

					int day = timeDateInfo::setStructTm()->tm_mday;
					int month = timeDateInfo::setStructTm()->tm_mon + 1;
					int year = timeDateInfo::setStructTm()->tm_year + 1900;
					int wday = timeDateInfo::setStructTm()->tm_wday;

					if (secArg == DATE_NEXT) {
						std::swap(secArg, firstArg);
					}

					//start of 'next month' method
					if (secArg == DATE_MONTH) {
						if (month == 12) {
							month = 1;
							year++;
						}
						else {
							month++;
						}

						count = TextStorage::getInstance()->displayMonthTasks(ALL_CODE, year, month);
						ComCalManager::getInstance()->setSideBarTitle(NEXT_MONTH_TITLE);
						timeDateInfo::setStructTm(year, month-1);

						return prepShowFeedback(NEXT_MONTH_TASKS_FEEDBACK, count);					
					}//end of next month method


					//start of show week of with a specific date inside
					if (secArg == DATE_WEEK) {
						Date startOfNextWeek = getNextWeekDate(year, month, day, wday);
						std::vector<Date> datesInWeek = getDatesInWeek(startOfNextWeek);

						count = TextStorage::getInstance()->displayWeekTasks(ALL_CODE, datesInWeek);
						ComCalManager::getInstance()->setSideBarTitle(NEXT_WEEK_TITLE);

						return prepShowFeedback(NEXT_WEEK_TASKS_FEEDBACK, count);
					}//end of show week with specified date

				}
				else {
					return INVALID_NEXT_INPUT;
				} 
			}//end of next week or next month method

			//start of deadlined task with specified date (default show all)
			if (firstArg == DEADLINED_TASK || secArg == DEADLINED_TASK) {

				if (secArg == DEADLINED_TASK) {
					std::swap(firstArg, secArg);
				}

				Date * tempDate = new Date();
				if (tempDate->setDate(secArg)) {
					count = TextStorage::getInstance()->displayDeadlinedTasks(ALL_CODE,*tempDate);
					sideBarTitle = tempDate->toGUIString() + ALL_TASKS_WITH_DEADLINE_TITLE;
					ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

					return prepShowFeedback(sideBarTitle, count);
				}
				else {
					return INVALID_DATE_INPUT;
				}
			}//end of deadlined task with specified date

			//start of partial with specified date
			if (firstArg == INPUT_PARTIAL || secArg == INPUT_PARTIAL) {
				if (secArg == INPUT_PARTIAL) {
					std::swap(firstArg, secArg);
				}

				Date * tempDate = new Date();
				if (tempDate->setDate(secArg)) {
					count = TextStorage::getInstance()->displayDeadlinedTasks(ALL_CODE, *tempDate);
					sideBarTitle = tempDate->toGUIString() + " " + ALL_PARTIAL_TASKS_TITLE;
					ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

					return prepShowFeedback(sideBarTitle, count);
				}
				else {
					return INVALID_DATE_INPUT;
				}
			}//end of partial with specified date


			//start of timed with specified date
			if (firstArg == INPUT_TIMED || secArg == INPUT_TIMED) {
				if (secArg == INPUT_TIMED) {
					std::swap(firstArg, secArg);
				}

				Date * tempDate = new Date();
				if (tempDate->setDate(secArg)) {
					count = TextStorage::getInstance()->displayTimedTasks(ALL_CODE, *tempDate);
					sideBarTitle = tempDate->toGUIString() + " " + ALL_TIMED_TASKS_TITLE;
					ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

					return prepShowFeedback(sideBarTitle, count);
				}
				else {
					return INVALID_DATE_INPUT;
				}
			}//end of timed with specified date

		}
		else { //argument now has only one word, numOfWhiteSpace == 0

			if (argument == INPUT_TODO) { // Display all tasks that are not done
				ComCalManager::getInstance()->setSideBarTitle(ALL_TODO_TITLE);
				count = TextStorage::getInstance()->displayTodoTasks();

				return prepShowFeedback(ALL_TODO_FEEDBACK, count);
			}

			if (argument == ALL_TASKS) {
				count = TextStorage::getInstance()->displayAllTasks();
				ComCalManager::getInstance()->setSideBarTitle(ALL_TASKS_TITLE);

				return prepShowFeedback(ALL_TASKS_FEEDBACK, count);
			}

			if (argument == INPUT_DONE) { // Display all tasks that are done
				count = TextStorage::getInstance()->displayDoneTasks();
				ComCalManager::getInstance()->setSideBarTitle(ALL_DONE_TITLE);

				return prepShowFeedback(ALL_DONE_FEEDBACK, count);
			}

			if (argument == DEADLINED_TASK) { 
				count = TextStorage::getInstance()->displayDeadlinedTasks();
				ComCalManager::getInstance()->setSideBarTitle(ALL_TASKS_WITH_DEADLINE_TITLE);

				return prepShowFeedback(ALL_DEADLINED_FEEDBACK, count);
			}

			if (argument == INPUT_TIMED) {
				count = TextStorage::getInstance()->displayTimedTasks();
				ComCalManager::getInstance()->setSideBarTitle(ALL_TIMED_TASKS_TITLE);

				return prepShowFeedback(ALL_TIMED_TASKS_FEEDBACK, count);
			}

			if (argument == FLOATING_TASKS) {
				count = TextStorage::getInstance()->displayFloatingTasks();
				ComCalManager::getInstance()->setSideBarTitle(ALL_FLOATING_TASKS_TITLE);

				return prepShowFeedback(ALL_FLOATING_TASKS_FEEDBACK, count);
			}

			if (argument == INPUT_PARTIAL) {
				count = TextStorage::getInstance()->displayPartialTask();
				ComCalManager::getInstance()->setSideBarTitle(ALL_PARTIAL_TASKS_TITLE);

				return prepShowFeedback(ALL_PARTIAL_TASKS_TITLE, count);
			}

			// User specifies "show 'month'" 
			int month = getMonthInput(argument);
			if (month != -1) {
				struct tm* date = timeDateInfo::setStructTm(month);
				int year = date->tm_year + 1900;

				count = TextStorage::getInstance()->displayMonthTasks(ALL_CODE, year, month + 1);
				ComCalManager::getInstance()->setSideBarTitle(argument + " tasks\n");

				return prepShowFeedback(timeDateInfo::getMonthStr(getMonthInput(argument)), count);
			}

			if (argument == WEEK) {
				std::vector<Date> weekDate = getDatesInWeek();

				count = TextStorage::getInstance()->displayWeekTasks(ALL_CODE, weekDate);
				ComCalManager::getInstance()->setSideBarTitle(THIS_WEEK_ALL_TASK);

				return prepShowFeedback(THIS_WEEK_TASKS_FEEDBACK, count);
			}

			//user specifies a date through the formats, dd/mm/yyyy || tomorrow,today,yesterday
			Date* showDate = new Date();
			if (showDate->setDate(argument)) {
				count = TextStorage::getInstance()->displayDatedTasks(ALL_CODE, *showDate);
				sideBarTitle = showDate->toGUIString();
				ComCalManager::getInstance()->setSideBarTitle(showDate->toString() + " tasks");

				return prepShowFeedback(sideBarTitle + " tasks", count);
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

std::vector<Date> Show::getDatesInWeek() {
	std::vector<Date> weekDate;

	struct tm * timeDetails = timeDateInfo::setStructTm();
	weekDate = getWeeklyDates(timeDetails->tm_year, timeDetails->tm_mon, timeDetails->tm_mday, timeDetails->tm_wday);

	return weekDate;
}


std::vector<Date> Show::getDatesInWeek(Date specDate) {
	std::vector<Date> weekDate;
	int year = specDate.getYear() + 1900;
	int month = specDate.getMonth() - 1;
	int mday = specDate.getDay();

	tm * timeDetails = timeDateInfo::setStructTm(year, month, mday);
	mktime(timeDetails);
	int wday = timeDetails->tm_wday;
	
	weekDate = getWeeklyDates(year, month, mday, wday);

	return weekDate;
}

std::vector<Date> Show::getWeeklyDates(int year, int month, int mday, int wday) {
	std::vector<Date> weekDate;

	if (wday != 0) {
		if (wday >= mday) {

			if (mday == 0) {
				year--;
				month = 11;
			}
			else {
				month--;
			}

			wday -= mday;
			mday = timeDateInfo::getDaysInMonth(month, year) - wday;
		}
		else {
			mday -= wday;
		}
	}

	for (int i = 0; i < DAYS_IN_WEEK; i++) {
		int tempMonth = month + 1;
		weekDate.push_back(Date(mday, tempMonth, year, 0000));

		if (mday == timeDateInfo::getDaysInMonth(month, year) && (month != 11)) {
			month++;
			mday = 1;
		}
		else {
			if ((mday == timeDateInfo::getDaysInMonth(month, year)) && (month == 11)){
				year++;
				month = 0;
				mday = 1;
			}
			else {
				mday++;
			}
		}
	}

	return weekDate;
}

std::vector<Date> Show::getWeeklyDates(struct tm* timeDetails) {
	std::vector<Date> weekDate;
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

		int tempMonth = month + 1;
		weekDate.push_back(Date(dayMonth, tempMonth, year, 0000));

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

std::string Show::prepShowFeedback(std::string feedback, int count) {
	if (count == 0) {
		return ZERO_SHOW_RESULTS;
	}
	else {
		return feedback + " " + SHOW_COUNT_START + typeConversions::intToString(count) + SHOW_COUNT_END;
	}
}

Date Show::getNextWeekDate(int year, int month, int mday, int wday) {
	int numDaysMonth = timeDateInfo::getDaysInMonth(month - 1, year);

	mday += DAYS_IN_WEEK - wday;
	if (numDaysMonth < mday) {
		mday %= numDaysMonth;
		if (month == 12) {
			month = 1;
			year++;
		}
		else {
			month++;
		}
	}

	Date startWeek(mday, month, year, 0000);

	return startWeek;
}

int Show::countWhiteSpace(std::string argument) {
	int numOfWhiteSpace = 0;

	for (int k = 0; k < argument.size(); k++) {
		if (isspace(argument[k])) {
			numOfWhiteSpace++;
		}
	}

	return numOfWhiteSpace;
}

bool Show::isTodoOrDone(std::string firstArg, std::string secArg, std::string thiArg) {
	if (isTodoOrDone(firstArg) || isTodoOrDone(secArg) || isTodoOrDone(thiArg)) {
		return true;
	}
	else {
		return false;
	}
}

bool Show::isTodoOrDone(std::string arg) {
	if (arg == INPUT_TODO || arg == INPUT_DONE) {
		return true;
	}
	else {
		return false;
	}
}

bool Show::isArgYear(std::string firstArg, std::string secArg, std::string thiArg) {
	if (timeDateInfo::isStringANum(firstArg) || timeDateInfo::isStringANum(secArg) || timeDateInfo::isStringANum(thiArg)) {
		return true;
	}
	else {
		return false;
	}
}

bool Show::isValidMonth(std::string firstArg, std::string secArg, std::string thiArg) {
	if (getMonthInput(firstArg) != -1 || getMonthInput(secArg) != -1 || getMonthInput(thiArg) != -1) {
		return true;
	}
	else{
		return false;
	}
}

bool Show::isWeek(std::string firstArg, std::string secArg, std::string thiArg) {
	if (firstArg == WEEK || secArg == WEEK || thiArg == WEEK) {
		return true;
	}
	else{
		return false;
	}
}


int Show::getCode(std::string arg) {
	if (arg == INPUT_DONE) {
		return DONE_CODE;
	}
	else {
		if (arg == INPUT_TODO) {
			return TODO_CODE;
		}
		else {
			return ALL_CODE;
		}
	}
}

std::string Show::showMonthYear(int code, int month, std::string firstArg, std::string secArg) {

	if (timeDateInfo::isStringANum(secArg) && secArg.size() == 4) {
		int year = typeConversions::stringToInt(secArg);

		if (year < 1900){
			return INVALID_YEAR_ERROR;
		}
		else {
			int count = TextStorage::getInstance()->displayMonthTasks(code, year, month + 1);
			struct tm* date = timeDateInfo::setStructTm(year, month);
			std::string sideBarTitle = prepSideBarTitleShowMonth(code, month, year);
			ComCalManager::getInstance()->setSideBarTitle(sideBarTitle);

			return prepShowFeedback(firstArg + " " + secArg, count);
		}
	}
	else{
		return INVALID_YEAR_ERROR;
	}
}

std::string Show::prepSideBarTitleShowMonth(int code, int month, int year) {
	std::string sideBarTitle = timeDateInfo::getMonthStr(month) + CAL_WHITE_SPACE + typeConversions::intToString(year);

	if (code == TODO_CODE) {
		sideBarTitle += CAL_WHITE_SPACE + DATED_TODO_TASKS;
		return sideBarTitle;
	}
	else {
		if (code == DONE_CODE) {
			sideBarTitle += CAL_WHITE_SPACE + DATED_DONE_TASKS;
			return sideBarTitle;
		}
		else {
			sideBarTitle += CAL_WHITE_SPACE + TASKS;
			return sideBarTitle;
		}
	}

	return sideBarTitle;
}