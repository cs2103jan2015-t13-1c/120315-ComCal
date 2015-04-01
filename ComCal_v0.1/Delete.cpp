// Delete.cpp
// Implementation of functions in the Delete class
//@author A0119754X

#include "Delete.h"
#include "typeConversions.h"
#include "TextStorage.h"

// TODO Implement input formats 3

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
		if (TextStorage::getInstance()->deleteTask(number - deletedCount)) {
			deletedTasks->push_back(number);
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

	deletedTasks = new std::vector<int>();
	deletedCount = 0;

	deleteMultipleTasks(argument);
	std::string returnString = "";
	unsigned int size = deletedTasks->size();

	if (size <= 0) {
		delete deletedTasks;
		return "Invalid delete command: No tasks deleted";
	}

	for (unsigned int i = 0; i < size; i++) {
		returnString += typeConversions::intToString(deletedTasks->at(i)) + " ";
	}
	delete deletedTasks;

	return ("Tasks " + returnString + "deleted.");
}