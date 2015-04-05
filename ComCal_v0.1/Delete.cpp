// Delete.cpp
// Implementation of functions in the Delete class
//@author A0119754X

#include "Delete.h"
#include "typeConversions.h"
#include "TextStorage.h"

// TODO Implement input formats 3

Delete::Delete() : Command() {
}

Delete::~Delete() {
}

void Delete::deleteMultipleTasks(std::string argument) {
	if (argument.size() <= 0) {
		return;
	}

	int space = argument.find(" ");
	std::string firstNumber = argument;
	std::string otherNumbers = "";

	if ((space != std::string::npos) && (space != -1)) {
		firstNumber = firstNumber.substr(0, space);
	}
	if ((space != std::string::npos) && (space != -1)) {
		otherNumbers = argument.substr(space + 1, argument.length() - space - 1);
	}

	if (typeConversions::isNumber(firstNumber)) {
		int number = typeConversions::stringToInt(firstNumber);
		if (TextStorage::getInstance()->getTask(number - deletedCount - 1) != NULL) {
			_deletedTasks.push_back(TextStorage::getInstance()->getTask(number - deletedCount - 1));
		}
		if (TextStorage::getInstance()->deleteTask(number - deletedCount)) {
			deletedTaskIndexes.push_back(number);
			deletedCount++;
		}
	}

	deleteMultipleTasks(otherNumbers);
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

	deletedCount = 0;

	deleteMultipleTasks(argument);
	std::string returnString = "";
	unsigned int size = deletedTaskIndexes.size();

	if (size <= 0) {
		return "Invalid delete command: No tasks deleted";
	}

	for (unsigned int i = 0; i < size; i++) {
		returnString += typeConversions::intToString(deletedTaskIndexes[i]) + " ";
	}

	return ("Task(s) " + returnString + "deleted.");
}

//@author A0085731A
std::string Delete::undo() {
	deletedCount = 0;
	
	std::string feedback = "Added task(s) ";

	for (unsigned int i = 0; i < _deletedTasks.size(); i++) {
		TextStorage::getInstance()->addTaskAtSpecificPosition(_deletedTasks[i], deletedTaskIndexes[i]);
		feedback += "(" + typeConversions::intToString(deletedTaskIndexes[i]) + ")";
		if (i < _deletedTasks.size() - 1) {
			feedback += ", ";
		}
	}

	return feedback;
}

std::string Delete::redo() {
	std::string feedback = "Task(s) ";
	
	for (unsigned int i = 0; i < deletedTaskIndexes.size(); i++) {
		TextStorage::getInstance()->deleteTask(deletedTaskIndexes[i] - deletedCount);
		deletedCount++;
		feedback += "(" + typeConversions::intToString(deletedTaskIndexes[i]) + ")";
		if (i < deletedTaskIndexes.size() - 1) {
			feedback += ", ";
		}
	}

	feedback += " deleted.";

	return feedback;
}
