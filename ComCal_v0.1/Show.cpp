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

std::string Show::execute(std::string argument) {
	std::string feedBack;
	Date* showDate = new Date();
	//TODO: add a function here to remove any white spaces from the left and right of 'argument'
	int numOfWhiteSpace = numOfWS(argument);

	if (argument.size() != 0){
		if (numOfWhiteSpace == 0) {

			//1st case: user specifies "show 'month'" without specifying the year
			if (getMonthInput(argument) != -1) {
				ComCalManager::getInstance()->setMonthDetails(timeDateInfo::setStructTm(getMonthInput(argument)));

				feedBack = timeDateInfo::getMonthStr(getMonthInput(argument)) + " shown";

				return  feedBack;
			}
			
			if (argument == INPUT_TODO || argument == INPUT_CAPT_TODO) {
				ComCalManager::getInstance()->setDefaultSideBar();

				feedBack = ALL_TODO_FEEDBACK;
				return feedBack;
			}
				
			if (argument == INPUT_DONE || argument == INPUT_CAPT_DONE) {
				setDoneSideBar();

				feedBack = ALL_DONE_FEEDBACK;
				return feedBack;
			}

			if (showDate->setDate(argument)){
				setShowDaySideBar(showDate);

				feedBack = showDate->toGUIString() + " shown";
				return feedBack;
			}
		}
		else{
			if (numOfWhiteSpace == 1) {

			}
		}
	}

	delete showDate;
	feedBack = INVALID_SHOW_INPUT;

	return feedBack;
}

void Show::setDoneSideBar() {
	int todoSize = TextStorage::getInstance()->getNumberOfTasks();

	ComCalManager::getInstance()->setSideBarTitle(ALL_DONE_TITLE);

	ComCalManager::getInstance()->getSideVec()->clear();
	for (int i = 0; i < todoSize; i++) {
		Task* tempTask = TextStorage::getInstance()->getTask(i);
		if (tempTask->getIsDone()) {
			ComCalManager::getInstance()->getSideVec()->push_back(tempTask->toGUIString());
		}
	}
}

void Show::setShowDaySideBar(Date* showDate){
	int todoSize = TextStorage::getInstance()->getNumberOfTasks();

	ComCalManager::getInstance()->setSideBarTitle(showDate->toGUIString() + " All Tasks");
	ComCalManager::getInstance()->getSideVec()->clear();

	Task* tempTask;
	for (int i = 0; i < todoSize; i++) {
		tempTask = TextStorage::getInstance()->getTask(i);
		if (tempTask->getStartDate() == showDate) {
			ComCalManager::getInstance()->getSideVec()->push_back(tempTask->toGUIString());
		}
	}
}

int Show::getMonthInput(std::string argument) {
	int monthIndex = -1;

	for (int i = 0; i < MONTHS_IN_YEAR; i++) {

		if (argument == timeDateInfo::getMonthStr(i)) {
			monthIndex = i;
			break;
		}

		if (argument == timeDateInfo::getLowerMonthStr(i)) {
			monthIndex = i;
			break;
		}

		if (argument == timeDateInfo::getShortMonthStr(i)) {
			monthIndex = i;
			break;
		}

		if (argument == timeDateInfo::getShortLowerMonthStr(i)) {
			monthIndex = i;
			break;
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

