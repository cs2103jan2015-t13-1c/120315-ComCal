// Save.cpp
// Implementation of functions in the Save class
//@author A0119754X

#include "Save.h"
#include "TextStorage.h"

std::string Save::execute(std::string argument) {
	if (argument.compare("") == 0) {
		argument = TextStorage::getInstance()->getTodoFileName();
	}
	TextStorage::getInstance()->saveTasks(argument);
	return ("Tasks saved to " + argument + " successfully.");
}