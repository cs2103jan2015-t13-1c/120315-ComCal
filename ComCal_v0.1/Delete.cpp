//@author A0085731A
// Delete.cpp
// Implementation of functions in the Delete class


#include "Delete.h"

// TODO Implement input formats 3

Delete::Delete() : Command() {
	_deletedCount = 0;
}

Delete::~Delete() {
}

void Delete::process(std::string argument) {
	if (support::isSpacesOnly(argument)) {
		throw exceptionInputInvalidSpacesOnly;
	}

	int numOfTasks = TextStorage::getInstance()->getNumberOfTasks();

	bool isProcessed = false;
	for (int i = 0; i < BEFOREKEYWORDSARRAYSIZE; i++) {
		int beforeKeywordPos = argument.find(BEFOREKEYWORDSARRAY[i]);
		if (beforeKeywordPos != std::string::npos) {
			if (isProcessed) {
				throw exceptionInputInvalidDelParams;
			}
			isProcessed = true;
			if (argument.find(BEFOREKEYWORDSARRAY[i]) != 0) {
				throw exceptionInputInvalidDelParams;
			}
			std::string dateString = argument.substr(BEFOREKEYWORDSARRAY[i].size());
			if(support::isSpacesOnly(dateString)) {
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
						_deletedTasksIndexes.push_back(j + 1);
					}
				}
				else if (task->hasStartDate()) {
					if (support::checkDateBefore(task->getStartDate(), date)) {
						_deletedTasksIndexes.push_back(j + 1);
					}
				}
			}
		}
	}

	if (!isProcessed) {
		if (argument.find(ALLKEYWORD) != std::string::npos) {
			if (argument.find(ALLKEYWORD) > 0) {
				throw exceptionInputInvalidDelParams;
			}
			for (int i = 0; i < numOfTasks; i++) {
				_deletedTasksIndexes.push_back(i+1);
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
				_deletedTasksIndexes.push_back(taskIndex);
				argument = argument.substr(nextSpacePos + 1);
				support::isSpacesOnly(argument);
				nextSpacePos = argument.find(" ");
			}

			if (!typeConversions::isNumber(argument)) {
				throw exceptionInputInvalidTaskIndex;
			}
			_deletedTasksIndexes.push_back(typeConversions::stringToInt(argument));
		}
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
		_deletedTasks.push_back(TextStorage::getInstance()->getTask(_deletedTasksIndexes[i] - _deletedCount-1));
		if (TextStorage::getInstance()->deleteTask(_deletedTasksIndexes[i] - _deletedCount)) {
			_deletedCount++;
			feedback += "(" + typeConversions::intToString(_deletedTasksIndexes[i]) + ")";
			if (i < _deletedTasksIndexes.size() - 1) {
				feedback += ", ";
			}
			else {
				feedback += ".";
			}
		}
		else {
			ErrorLog::inputErrorLog("Unsuccessful delete, please check delete class.");
		}
	}

	return feedback;
}

//@author A0085731A
std::string Delete::undo() {
	_deletedCount = 0;

	std::string feedback = "Undo delete: Added task(s): ";

	for (unsigned int i = 0; i < _deletedTasksIndexes.size(); i++) {
		if (_deletedTasksIndexes[i] >= TextStorage::getInstance()->getNumberOfTasks()) {
			TextStorage::getInstance()->addTask(_deletedTasks[i]);
		}
		else{
			TextStorage::getInstance()->addTaskAtSpecificPosition(_deletedTasks[i], _deletedTasksIndexes[i]);
		}
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
		if (TextStorage::getInstance()->deleteTask(_deletedTasksIndexes[i] - _deletedCount)) {
			_deletedCount++;
			feedback += "(" + typeConversions::intToString(_deletedTasksIndexes[i]) + ")";
			if (i < _deletedTasksIndexes.size() - 1) {
				feedback += ", ";
			}
			else {
				feedback += ".";
			}
		}
		else {
			ErrorLog::inputErrorLog("Unsuccessful delete, please check delete class.");
		}
	}

	return feedback;
}
