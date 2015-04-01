// Load.cpp
// Implementation of functions in the Load class
//@author A0119754X

#include "Load.h"
#include "TextStorage.h"

std::string Load::execute(std::string argument) {
	if (argument.compare("") == 0) {
		argument = TextStorage::getInstance()->getTodoFileName();
	}
	TextStorage::getInstance()->loadTasks(argument);
	return ("Tasks loaded from " + argument + " successfully.");
}