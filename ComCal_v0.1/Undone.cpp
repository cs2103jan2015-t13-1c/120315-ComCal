// Undone.cpp
// Implementation of functions in the Undone class
//@author A0085731A

#include "Undone.h"

// TODO Implement input formats 3

Undone::Undone() : Command() {
}

Undone::~Undone() {
}

void Undone::process(std::string argument) {
	if (support::isSpacesOnly(argument)) {
		throw exceptionInputInvalidSpacesOnly;
	}

	int numOfTasks = TextStorage::getInstance()->getNumberOfTasks();

	bool isProcessed = false;
	for (int i = 0; i < BEFOREKEYWORDSARRAYSIZE; i++) {
		int beforeKeywordPos = argument.find(BEFOREKEYWORDSARRAY[i]);
		if (beforeKeywordPos != std::string::npos) {
			if (isProcessed) {
				throw exceptionInputInvalidUndoneParams;
			}
			isProcessed = true;
			if (argument.find(BEFOREKEYWORDSARRAY[i]) != 0) {
				throw exceptionInputInvalidUndoneParams;
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
						_undoneTasksIndexes.push_back(j + 1);
					}
				}
				else if (task->hasStartDate()) {
					if (support::checkDateBefore(task->getStartDate(), date)) {
						_undoneTasksIndexes.push_back(j + 1);
					}
				}
			}
		}
	}

	if (!isProcessed) {
		if (argument.find(ALLKEYWORD) != std::string::npos) {
			if (argument.find(ALLKEYWORD) > 0) {
				throw exceptionInputInvalidUndoneParams;
			}
			for (int i = 0; i < numOfTasks; i++) {
				_undoneTasksIndexes.push_back(i + 1);
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
				_undoneTasksIndexes.push_back(taskIndex);
				argument = argument.substr(nextSpacePos + 1);
				support::isSpacesOnly(argument);
				nextSpacePos = argument.find(" ");
			}

			if (!typeConversions::isNumber(argument)) {
				throw exceptionInputInvalidTaskIndex;
			}
			_undoneTasksIndexes.push_back(typeConversions::stringToInt(argument));
		}
	}

	std::sort(_undoneTasksIndexes.begin(), _undoneTasksIndexes.end());

	return;
}

std::string Undone::execute(std::string argument) {
	// Formats:
	// 1. Undone single task
	//    - undone 1
	// 2. Undone multiple tasks
	//    - undone 1 2 3
	// 3. Undone all tasks before date
	//    - undone before 22/12/14
	//    - undone .b 22/12/14

	std::string feedback = "Marked incomplete task(s): ";

	process(argument);

	for (unsigned int i = 0; i < _undoneTasksIndexes.size(); i++) {
		if (TextStorage::getInstance()->getTask(_undoneTasksIndexes[i] - 1) != NULL) {
			_undoneTasks.push_back(TextStorage::getInstance()->getTask(_undoneTasksIndexes[i] - 1));
			TextStorage::getInstance()->getTask(_undoneTasksIndexes[i] - 1)->undone();
			feedback += "(" + typeConversions::intToString(_undoneTasksIndexes[i]) + ")";
			if (i < _undoneTasksIndexes.size() - 1) {
				feedback += ", ";
			}
			else {
				feedback += ".";
			}
		}
		else {
			ErrorLog::inputErrorLog("Unsuccessful undone, please check undone class.");
			assert(TextStorage::getInstance()->getTask(_undoneTasksIndexes[i] - 1) != NULL);
		}
	}

	return feedback;
}

//@author A0085731A
std::string Undone::undo() {
	std::string feedback = "Undo undone: Marked complete task(s): ";

	for (unsigned int i = 0; i < _undoneTasks.size(); i++) {
		_undoneTasks[i]->done();
		feedback += "(" + typeConversions::intToString(_undoneTasksIndexes[i]) + ")";
		if (i < _undoneTasksIndexes.size() - 1) {
			feedback += ", ";
		}
		else {
			feedback += ".";
		}
	}

	return feedback;
}

std::string Undone::redo() {
	std::string feedback = "Redo undone: Marked incomplete task(s): ";

	for (unsigned int i = 0; i < _undoneTasks.size(); i++) {
		_undoneTasks[i]->undone();
		feedback += "(" + typeConversions::intToString(_undoneTasksIndexes[i]) + ")";
		if (i < _undoneTasksIndexes.size() - 1) {
			feedback += ", ";
		}
		else {
			feedback += ".";
		}
	}

	return feedback;
}
