// Load.cpp
// Implementation of functions in the Load class
//@author A0119754X

#include "Load.h"

Load::Load() : Command() {
}

Load::~Load() {
}

std::string Load::execute(std::string argument) {
	if (argument.compare("") == 0) {
		argument = TextStorage::getInstance()->getTodoFileName();
	}
	if (TextStorage::getInstance()->loadTasks(argument)) {
		return ("Tasks loaded from " + argument + " successfully.");
	}
	return ("Loading failed. File " + argument + " does not exist.");
}