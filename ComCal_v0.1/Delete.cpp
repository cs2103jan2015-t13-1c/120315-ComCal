// Delete.cpp
// Implementation of functions in the Delete class
//@author A0119754X

#include "Delete.h"
#include "typeConversions.h"
#include "TextStorage.h"

std::string Delete::execute(std::string argument) {
	// Formats:
	// 1. Delete single task
	//    - delete 1
	// 2. Delete multiple tasks
	//    - delete 1 2 3
	// 3. Delete all tasks before date
	//    - delete before 22/12/14
	//    - delete .b 22/12/14

	if (!typeConversions::isNumber(argument))
		return "Invalid delete command: Argument should be an index";

	// TODO Implement input formats 2 and 3
	if (TextStorage::getInstance()->deleteTask(typeConversions::stringToInt(argument))) {
		return "Task " + argument + " deleted";
	}
	return "Task " + argument + " not found; nothing deleted";
}