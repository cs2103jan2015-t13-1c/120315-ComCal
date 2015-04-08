// Delete.cpp
// Implementation of functions in the Delete class
//@author A0085731A

#include "Delete.h"

// TODO Implement input formats 3

Delete::Delete() : Command() {
	_deletedCount = 0;
}

Delete::~Delete() {
}

bool Delete::checkDateBefore(Date* dateToBeChecked, Date* dateToCheckWith) {
	if (dateToBeChecked->getTimeT() < dateToCheckWith->getTimeT()) {
		return true;
	}
	else {
		return false;
	}
}

void Delete::process(std::string argument) {
	int numOfTasks = TextStorage::getInstance()->getNumberOfTasks();
	
	bool isProcessed = false;
	for (int i = 0; i < DELETEBEFOREKEYWORDSARRAYSIZE; i++) {
		int deleteBeforeKeywordPos = argument.find(DELETEBEFOREKEYWORDSARRAY[i]);
		if (deleteBeforeKeywordPos!=std::string::npos) {
			if (isProcessed) {
				throw exceptionInputInvalidDeleteParams;
			}
			isProcessed = true;
			if (argument.find(DELETEBEFOREKEYWORDSARRAY[i]) != 0) {
				throw exceptionInputInvalidDeleteParams;
			}
			Date* date = new Date;
			if (!date->setDate(argument.substr(DELETEBEFOREKEYWORDSARRAY[i].size()))) {
				throw exceptionInputInvalidDateTimeAddEdit;
			}
			for (int j = 0; j < numOfTasks; j++) {
				Task* task = TextStorage::getInstance()->getTask(j);
				if (task->hasStartDate() && task->hasEndDate() || task->hasEndDate()) {
					if (checkDateBefore(task->getEndDate(),date)) {
						_deletedTasksIndexes.push_back(j);
						_deletedTasks.push_back(task);
					}
				}
				else if (task->hasStartDate()) {
					if (checkDateBefore(task->getStartDate(), date)) {
						_deletedTasksIndexes.push_back(j);
						_deletedTasks.push_back(task);
					}
				}
			}
		}
	}

	if (!isProcessed) {
		int nextSpacePos = argument.find(" ");
		while (nextSpacePos != std::string::npos) {
			std::string taskIndexString = argument.substr(0, nextSpacePos);
			if (!typeConversions::isNumber(taskIndexString)) {
				throw exceptionInputInvalidTaskIndex;
			}
			int taskIndex = typeConversions::stringToInt(taskIndexString);
			if (taskIndex<1 || taskIndex > numOfTasks) {
				throw exceptionInputInvalidTaskIndex;
			}
			_deletedTasksIndexes.push_back(typeConversions::stringToInt(taskIndexString));
			argument = argument.substr(nextSpacePos+1);
			nextSpacePos = argument.find(" ");
		}

		if (!typeConversions::isNumber(argument)) {
			throw exceptionInputInvalidTaskIndex;
		}
		_deletedTasksIndexes.push_back(typeConversions::stringToInt(argument));
	}

	std::sort(_deletedTasksIndexes.begin(), _deletedTasksIndexes.end());
	
	return;
}

std::string Delete::execute(std::string argument) {
	// Formats:
	// 1. Delete single task
	//    - delete 1
	// 2. Delete multiple tasks
	//    - delete 1 2 3
	// 3. Delete all tasks before date
	//    - delete before 22/12/14
	//    - delete .b 22/12/14

	std::string feedback = "Deleted task(s): ";

	process(argument);

	for (unsigned int i = 0; i < _deletedTasksIndexes.size(); i++) {
		Task* deletedTask = TextStorage::getInstance()->getTask(_deletedTasksIndexes[i] - _deletedCount);
		_deletedTasks.push_back(deletedTask);
		TextStorage::getInstance()->deleteTask(_deletedTasksIndexes[i] - _deletedCount);
		_deletedCount++;
		feedback += typeConversions::intToString(_deletedTasksIndexes[i]);
		if (i < _deletedTasksIndexes.size() - 1) {
			feedback += ", ";
		}
		else {
			feedback += ".";
		}
	}

	return feedback;
}

//@author A0085731A
std::string Delete::undo() {
	_deletedCount = 0;

	std::string feedback = "Undo delete: Added task(s): ";

	for (unsigned int i = 0; i < _deletedTasks.size(); i++) {
		TextStorage::getInstance()->addTaskAtSpecificPosition(_deletedTasks[i], _deletedTasksIndexes[i]);
		feedback += "(" + typeConversions::intToString(_deletedTasksIndexes[i]) + ")";
		if (i < _deletedTasks.size() - 1) {
			feedback += ", ";
		}
		else {
			feedback += ".";
		}
	}

	return feedback;
}

std::string Delete::redo() {
	std::string feedback = "Redo delete: Deleted task(s): ";
	
	for (unsigned int i = 0; i < _deletedTasksIndexes.size(); i++) {
		TextStorage::getInstance()->deleteTask(_deletedTasksIndexes[i] - _deletedCount);
		_deletedCount++;
		feedback += "(" + typeConversions::intToString(_deletedTasksIndexes[i]) + ")";
		if (i < _deletedTasksIndexes.size() - 1) {
			feedback += ", ";
		}
		else {
			feedback += ".";
		}
	}

	return feedback;
}
