//@author A0116683B
// Save.cpp
// Implementation of functions in the Save class

#include "Save.h"

Save::Save() : Command() {
}

Save::~Save() {
}

std::string Save::execute(std::string argument) {
	if (argument.compare("") == 0) {
		argument = TextStorage::getInstance()->getTodoFileName();
	}
	if (TextStorage::getInstance()->saveTasks(argument)) {
		return ("Tasks saved to " + argument + " successfully.");
	}
	return ("Failed to save to " + argument);
}