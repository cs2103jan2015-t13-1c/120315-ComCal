//@author A0085731A
// Done.cpp
// Implementation of functions in the Delete class

#include "Done.h"

Done::Done() : Command() {
}

Done::~Done() {
}

void Done::process(std::string argument) {
	if (support::isSpacesOnly(argument)) {
		throw exceptionInputInvalidSpacesOnly;
	}

	int numOfTasks = TextStorage::getInstance()->getNumberOfTasks();

	bool isProcessed = false;
	for (int i = 0; i < BEFOREKEYWORDSARRAYSIZE; i++) {
		int beforeKeywordPos = argument.find(BEFOREKEYWORDSARRAY[i]);
		if (beforeKeywordPos != std::string::npos) {
			if (isProcessed) {
				throw exceptionInputInvalidDoneParams;
			}
			isProcessed = true;
			if (argument.find(BEFOREKEYWORDSARRAY[i]) != 0) {
				throw exceptionInputInvalidDoneParams;
			}
			std::string dateString = argument.substr(BEFOREKEYWORDSARRAY[i].size());
			if (support::isSpacesOnly(dateString)) {
				throw exceptionInputInvalidSpacesOnly;
			}
			Date* date = new Date;
			if (!date->setDate(dateString)) {
				throw exceptionInputInvalidDateTimeAddEdit;
			}
			date->setTime(0);
			for (int j = 0; j < numOfTasks; j++) {
				Task* task = TextStorage::getInstance()->getTask(j);
				if (task->hasStartDate() && task->hasEndDate() || task->hasEndDate()) {
					if (support::checkDateBefore(task->getEndDate(), date)) {
						_doneTasksIndexes.push_back(j + 1);
					}
				}
				else if (task->hasStartDate()) {
					if (support::checkDateBefore(task->getStartDate(), date)) {
						_doneTasksIndexes.push_back(j + 1);
					}
				}
			}
		}
	}

	if (!isProcessed) {
		if (argument.find(ALLKEYWORD) != std::string::npos) {
			if (argument.find(ALLKEYWORD) > 0) {
				throw exceptionInputInvalidDoneParams;
			}
			for (int i = 0; i < numOfTasks; i++) {
				_doneTasksIndexes.push_back(i + 1);
			}
		}
		else {
			int nextSpacePos = argument.find(" ");
			while (nextSpacePos != std::string::npos) {
				std::string taskIndexString = argument.substr(0, nextSpacePos);
				if (!typeConversions::isNumber(taskIndexString)) {
					throw exceptionInputInvalidTaskIndex;
				}
				int taskIndex = typeConversions::stringToInt(taskIndexString);
				if (taskIndex < 1 || taskIndex > numOfTasks) {
					throw exceptionInputInvalidTaskIndex;
				}
				_doneTasksIndexes.push_back(taskIndex);
				argument = argument.substr(nextSpacePos + 1);
				support::isSpacesOnly(argument);
				nextSpacePos = argument.find(" ");
			}

			if (!typeConversions::isNumber(argument)) {
				throw exceptionInputInvalidTaskIndex;
			}
			_doneTasksIndexes.push_back(typeConversions::stringToInt(argument));
		}
	}

	std::sort(_doneTasksIndexes.begin(), _doneTasksIndexes.end());

	return;
}

std::string Done::execute(std::string argument) {
	// Formats:
	// 1. Done single task
	//    - done 1
	// 2. Done multiple tasks
	//    - done 1 2 3
	// 3. Done all tasks before date
	//    - done before 22/12/14
	//    - done .b 22/12/14

	std::string feedback = "Marked completed task(s): ";

	process(argument);

	for (unsigned int i = 0; i < _doneTasksIndexes.size(); i++) {
		if (TextStorage::getInstance()->getTask(_doneTasksIndexes[i] - 1) != NULL) {
			_doneTasks.push_back(TextStorage::getInstance()->getTask(_doneTasksIndexes[i] - 1));
			TextStorage::getInstance()->getTask(_doneTasksIndexes[i] - 1)->done();
			feedback += "(" + typeConversions::intToString(_doneTasksIndexes[i]) + ")";
			if (i < _doneTasksIndexes.size() - 1) {
				feedback += ", ";
			}
			else {
				feedback += ".";
			}
		}
		else {
			ErrorLog::inputErrorLog("Unsuccessful done, please check done class.");
			assert(TextStorage::getInstance()->getTask(_doneTasksIndexes[i] - 1) != NULL);
		}
	}

	return feedback;
}

std::string Done::undo() {
	std::string feedback = "Undo done: Marked incomplete task(s): ";

	for (unsigned int i = 0; i < _doneTasks.size(); i++) {
		_doneTasks[i]->undone();
		feedback += "(" + typeConversions::intToString(_doneTasksIndexes[i]) + ")";
		if (i < _doneTasksIndexes.size() - 1) {
			feedback += ", ";
		}
		else {
			feedback += ".";
		}
	}

	return feedback;
}

std::string Done::redo() {
	std::string feedback = "Redo done: Marked complete task(s): ";

	for (unsigned int i = 0; i < _doneTasks.size(); i++) {
		_doneTasks[i]->done();
		feedback += "(" + typeConversions::intToString(_doneTasksIndexes[i]) + ")";
		if (i < _doneTasksIndexes.size() - 1) {
			feedback += ", ";
		}
		else {
			feedback += ".";
		}
	}

	return feedback;
}
